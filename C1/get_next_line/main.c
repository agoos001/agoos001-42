

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open
#include <unistd.h> // close


int main()
{
	char *str, *str1;
setbuf(stdout, NULL);
	// int fd = open("tm.txt", O_RDONLY);
	// int	fd1 = open("tm1.txt", O_RDONLY);
	// for (int i = 0; i < 1; i++)
	// {
		// str = get_next_line(fd);
		// str1 = get_next_line(fd1);
		// printf("fd: %s\n", str);
		// printf("fd1: %s\n", str1);
		// free(str);
		// free(str1);
	// int fd = open("tm.txt", O_RDONLY);
	// int	fd1 = open("tm1.txt", O_RDONLY);
	// for (int i = 0; i < 1; i++)
	// {
		str = get_next_line(0);
		printf("fd: %s\n", str);
		// free(str);
		str = get_next_line(0);
		printf("fd: %s\n", str);
		// free(str);
	// }
	// 	free(str);
	// 	free(str1);
	return (0);
}
