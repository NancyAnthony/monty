#include "monty.h"
/**
 * pchar_opcode - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void pchar_opcode(stack_t **head, unsigned int count)
{
	stack_t *tp;

	tp = *head;
	if (!tp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tp->n > 127 || tp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tp->n);
}
