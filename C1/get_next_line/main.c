

#include "get_next_line.h"
#include <stdio.h>


int main()
{
	setbuf(stdout, NULL);
	char *str = get_next_line(0);
	for (int i = 0; i < 2; i++)
	{
		printf("result: %s", str);
	}
	free(str);
	return (0);
}
