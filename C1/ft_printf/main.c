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

	ft_printf("cpy: %-20s\n", "agoos");
	printf("org: %-20.5s\n", "agoos");

	return (0);
}
