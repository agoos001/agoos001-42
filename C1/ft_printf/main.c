#include "ft_printf.h"

#include <limits.h>
#include <stdio.h>

int main()
{
	int x , y;
	x = y = 0;
	
	setbuf(stdout, NULL);
	printf("\n----------- TEST: SHARP HEX -----------\n\n");
	x = printf("  Or:\tNumber [%#x]\n", 0);
	y = ft_printf("  Ft:\tNumber [%#x]\n", 0);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = printf("  Or:\tNumber [%#x]\n", LONG_MIN);
	y = ft_printf("  Ft:\tNumber [%#x]\n", LONG_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = printf("  Or:\tNumber [%#x]\n", 42);
	y = ft_printf("  Ft:\tNumber [%#x]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = printf("  Or:\tNumber [%#X]\n", 42);
	y = ft_printf("  Ft:\tNumber [%#X]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	return (0);
}
