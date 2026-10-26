#include "ft_printf.h"

int main()
{
	// ------------s - c---------------
	// ft_printf("cpy: %.0s\n", "is the bes");
	// printf("org: %.0s\n", "is the bes");
	//
	// ft_printf("cpy: %.1s\n", "is the bes");
	// printf("org: %.1s\n", "is the bes");
	
	// ft_printf("cpy: %.s\n", "is the bes");
	// printf("org: %.s\n", "is the bes");

	// ft_printf("cpy: %-20s\n", "agoos");
	// printf("org: %-20.5s\n", "agoos");




	//------------d - i ---------------
	// ft_printf("cpy: %10d\n", 10);
	// printf("org: %10d\n", 10);
	
	// ft_printf("cpy: %10i\n", 10);
	// printf("org: %10i\n", 10);


	// -----------------p -----------------
	// int integer = 20;
	// int *ptr = &integer;
	// ft_printf("cpy: %-20.5p\n", ptr);
	// printf("org: %-20.5p\n", ptr);
	
	// ----------------u------
	ft_printf("cpy: %20u\n", -1);
	printf("org: %20u\n", -1);
	return (0);
}
