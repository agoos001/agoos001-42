#include "ft_printf.h"

#include <limits.h>
#include <stdio.h>

int main()
{
	int x , y;
	x = y = 0;
	
	setbuf(stdout, NULL);
	printf("\n----------- TEST: %%d -----------\n\n");
	printf("Testing: (\"\\t%%d\\n\", 42)\n");
	x += printf("  Or\t:\t%d\n", 42);
	y += ft_printf("  Ft\t:\t%d\n", 42);
	printf("Printf = %d \n, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe number %%d is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe number %d is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe number %d is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%d\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%d\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%d\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%d\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%d\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%d\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MIN - INT_MIN)\n");
	x += printf("  Or\t:\t%i\n", INT_MIN - INT_MIN);
	y += ft_printf("  Ft\t:\t%i\n", INT_MIN - INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	return (0);
}
