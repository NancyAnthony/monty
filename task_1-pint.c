#include "monty.h"
/**
 * pint_opcodes - prints the top
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void pint_opcodes(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
