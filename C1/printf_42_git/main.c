#include "ft_printf.h"
#include <stdio.h>

int main()
{
	// setbuf(stdout, NULL);
	fclose(stdout);
	printf(stderr, "ft_ %d \n", ft_printf("agoos"));
	printf(stderr, "OG_ %d \n", ft_printf("agoos"));
}

