#include "monty.h"

/**
 *
 *
 */

int main(int ac, char **av)
{
	FILE *file;
	char error_msg[30];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		sprintf(error_msg, "Error: Can't open file %s", av[1]);
		perror(error_msg);
		exit(EXIT_FAILURE);
	}
return 0;
}
