#include "ft_printf.h"

#include <limits.h>
#include <stdio.h>

int main()
{
	setbuf(stdout, NULL);
	printf("  Or:\tNumber [%011i]\n", (int)LONG_MAX);
	ft_printf("  Ft:\tNumber [%011i]\n", LONG_MAX);

	return (0);
}
