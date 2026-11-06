/* ************************************************************************** */
/*   main_tester.c : ft_printf tester (mandatory + bonus "# +")               */
/*                                                                            */
/*   Compile:                                                                 */
/*   cc -Wno-format -Wno-format-security -I. main_tester.c libftprintf.a \    */
/*      -o tester && ./tester                                                 */
/*                                                                            */
/*   Optional: -DBONUS=0 to skip the flags tests                              */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_printf.h"

#ifndef BONUS
# define BONUS 1
#endif

#define BUF 8192
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	g_total;
static int	g_fail;

static void	start(int *saved, const char *path)
{
	int	fd;

	fflush(stdout);
	*saved = dup(1);
	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(fd, 1);
	close(fd);
}

static int	stop(int saved, const char *path, char *buf)
{
	int		fd;
	ssize_t	n;

	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	fd = open(path, O_RDONLY);
	n = read(fd, buf, BUF - 1);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	close(fd);
	return ((int)n);
}

static void	show(const char *label, const char *s, int n)
{
	int	i;

	printf("   %s: [", label);
	for (i = 0; i < n; i++)
	{
		if (s[i] == '\0')
			printf("\\0");
		else if (s[i] == '\n')
			printf("\\n");
		else
			printf("%c", s[i]);
	}
	printf("]\n");
}

static void	check(const char *fmt, char *a, int na, char *b, int nb,
		int r1, int r2)
{
	g_total++;
	if (na == nb && memcmp(a, b, na) == 0 && r1 == r2)
	{
		printf(GREEN "[OK]" RESET " %s\n", fmt);
		return ;
	}
	g_fail++;
	printf(RED "[KO]" RESET " %s\n", fmt);
	show("ft_printf", a, na);
	show("printf   ", b, nb);
	printf("   return: ft=%d real=%d\n", r1, r2);
}

#define T(...) do { \
	char	a[BUF]; \
	char	b[BUF]; \
	int		sv; \
	int		r1; \
	int		r2; \
	int		na; \
	int		nb; \
	start(&sv, "/tmp/ft_out.txt"); \
	r1 = ft_printf(__VA_ARGS__); \
	na = stop(sv, "/tmp/ft_out.txt", a); \
	start(&sv, "/tmp/real_out.txt"); \
	r2 = printf(__VA_ARGS__); \
	nb = stop(sv, "/tmp/real_out.txt", b); \
	check(#__VA_ARGS__, a, na, b, nb, r1, r2); \
} while (0)

static void	title(const char *s)
{
	printf("\n=== %s ===\n", s);
}

int	main(void)
{
	char	*nul = NULL;
	char	*empty = "";
	int		x = 42;

	title("%% and plain text");
	T("%%");
	T("%%%%");
	T("100%%");
	T("a%%b%%c");
	T("hello world");
	T("");
	T("\n");
	T("%c%%%c", 'a', 'b');

	title("%c");
	T("%c", 'A');
	T("%c", '0');
	T("%c", ' ');
	T("%c", 0);
	T("%c%c%c", 'a', 0, 'b');
	T("[%c] [%c]", 'x', 'y');
	T("%c", 127);
	T("%c", 255);

	title("%s");
	T("%s", "hello");
	T("%s", empty);
	T("%s", nul);
	T("[%s]", "a b c");
	T("%s %s %s", "a", "bb", "ccc");
	T("%s%s", "salam", "world");
	T("%s\n", "with newline");
	T("%s", "very long string very long string very long string 1234567890");

	title("%p");
	T("%p", &x);
	T("%p", "salam");
	T("%p", (void *)0);
	T("%p", nul);
	T("%p", (void *)1);
	T("%p", (void *)15);
	T("%p", (void *)16);
	T("%p", (void *)255);
	T("%p", (void *)-1);
	T("%p", (void *)LONG_MAX);
	T("%p", (void *)LONG_MIN);
	T("%p %p", (void *)1, (void *)16);
	T("%p %p %p", &x, nul, &x);

	title("%d");
	T("%d", 0);
	T("%d", 1);
	T("%d", -1);
	T("%d", 9);
	T("%d", 10);
	T("%d", 42);
	T("%d", -42);
	T("%d", 100);
	T("%d", 12345);
	T("%d", INT_MAX);
	T("%d", INT_MIN);
	T("%d", INT_MAX - 1);
	T("%d", INT_MIN + 1);
	T("%d %d %d", 7, -7, 100);
	T("[%d][%d]", 0, 0);

	title("%i");
	T("%i", 0);
	T("%i", 42);
	T("%i", -42);
	T("%i", INT_MAX);
	T("%i", INT_MIN);
	T("%i %i", 1, -1);

	title("%u");
	T("%u", 0);
	T("%u", 1);
	T("%u", 42);
	T("%u", -1);
	T("%u", UINT_MAX);
	T("%u", INT_MAX);
	T("%u", INT_MIN);
	T("%u", 3000000000u);
	T("%u %u", 10u, 99u);

	title("%x");
	T("%x", 0);
	T("%x", 1);
	T("%x", 9);
	T("%x", 10);
	T("%x", 15);
	T("%x", 16);
	T("%x", 255);
	T("%x", 256);
	T("%x", 4096);
	T("%x", -1);
	T("%x", INT_MAX);
	T("%x", INT_MIN);
	T("%x", UINT_MAX);
	T("%x", 3735928559u);
	T("%x %x", 1, 2);

	title("%X");
	T("%X", 0);
	T("%X", 255);
	T("%X", 3735928559u);
	T("%X", -1);
	T("%X", UINT_MAX);
	T("%X", INT_MIN);
	T("%x %X", 48879, 48879);

	title("mixed");
	T("%c %s %p %d %i %u %x %X %%", 'a', "b", &x, 1, 2, 3, 255, 255);
	T("%s|%d|%x|%p", nul, 0, 0, (void *)0);
	T("%d%d%d%d", 1, 2, 3, 4);
	T("%d %s %c", 42, "salam", 'Z');
	T("%x%X%x%X", 10, 10, 11, 11);
	T("%%d %d", 5);
	T("%%%d%%", 5);
	T("%c%s%c", '[', "mid", ']');

#if BONUS
	title("BONUS: flag #");
	T("%#x", 0);
	T("%#x", 1);
	T("%#x", 255);
	T("%#x", 4096);
	T("%#x", -1);
	T("%#x", UINT_MAX);
	T("%#X", 0);
	T("%#X", 255);
	T("%#X", 3735928559u);
	T("%#x %#X", 255, 255);
	T("%#x|%#x", 0, 1);
	T("[%#x]", 16);

	title("BONUS: flag +");
	T("%+d", 0);
	T("%+d", 1);
	T("%+d", -1);
	T("%+d", 42);
	T("%+d", -42);
	T("%+d", INT_MAX);
	T("%+d", INT_MIN);
	T("%+i", 0);
	T("%+i", 42);
	T("%+i", -42);
	T("%+i", INT_MAX);
	T("%+i", INT_MIN);
	T("%+d %+d %+d", 1, -1, 0);
	T("[%+d]", 7);

	title("BONUS: flag space");
	T("% d", 0);
	T("% d", 1);
	T("% d", -1);
	T("% d", 42);
	T("% d", -42);
	T("% d", INT_MAX);
	T("% d", INT_MIN);
	T("% i", 0);
	T("% i", 42);
	T("% i", -42);
	T("% i", INT_MAX);
	T("% i", INT_MIN);
	T("% d % d % d", 1, -1, 0);
	T("[% d]", 7);

	title("BONUS: combinations");
	T("%+ d", 42);
	T("% +d", 42);
	T("%+ d", -42);
	T("% +d", -42);
	T("%+ i", 42);
	T("% +i", -42);
	T("%#x %+d % d", 255, 42, 42);
	T("%#X %+i % i", 255, -42, -42);
	T("%+d%%", 100);
	T("% d%%", 100);
	T("%#x%%", 255);
#endif

	printf("\n==============================\n");
	printf("Total: %d | ", g_total);
	printf(GREEN "OK: %d" RESET " | ", g_total - g_fail);
	if (g_fail)
		printf(RED "KO: %d" RESET "\n", g_fail);
	else
		printf("KO: 0 \n");
	return (g_fail != 0);
}
