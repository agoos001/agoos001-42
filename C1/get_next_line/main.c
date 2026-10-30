

#include "get_next_line.h"
#include <stdio.h>


int main()
{
	setbuf(stdout, NULL);
	printf("result: %s", get_next_line(0));

	return (0);
}
