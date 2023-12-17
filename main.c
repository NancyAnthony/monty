#include "monty.h"
programData_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @ac: number of arguments
 * @av: monty file location
 * Return: 0 on success
 */
int main(int ac, char **av);
int main(int ac, char **av)
{
	FILE *montyFile;
	char error_msg[30];
	size_t len = 0;
	ssize_t line_ptr = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	char *data;


	/* Checks if argument is 2 */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* File is opened in read only mode*/
	montyFile = fopen(av[1], "r");
	/*bus.montyFile = montyFile;*/

		/* Checks if file cannot be opened */
		if (montyFile == NULL)
		{
			sprintf(error_msg, "Error: Can't open file %s", av[1]);
			perror(error_msg);
			exit(EXIT_FAILURE);
		}

	while (line_ptr > 0)
	{
		data = NULL;
		line_ptr = getline(&data, &len, montyFile);
		bus.data = data;
		counter++;
		if (line_ptr > 0)
		{
			handle_ops(data, &stack, counter, montyFile);
		}
		free(data);
	}
	free_stack(stack);
	fclose(montyFile);

	return (0);
}


