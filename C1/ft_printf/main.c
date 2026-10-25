#include "ft_printf.h"

int main()
{
	// ft_printf("cpy: %.0s\n", "is the bes");
	// printf("org: %.0s\n", "is the bes");
	//
	// ft_printf("cpy: %.1s\n", "is the bes");
	// printf("org: %.1s\n", "is the bes");
	
	// ft_printf("cpy: %.s\n", "is the bes");
	// printf("org: %.s\n", "is the bes");

	ft_printf("cpy: %10s\n", "is the bes");
	printf("org: %10s\n", "is the bes");

	return (0);
}
