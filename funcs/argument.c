#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **av)
{
	int i = 0;
	while (i < argc)
	{
		printf("argv[%d] : %s\n", i, av[i]);
		i++;
	}
	return 0;
}
