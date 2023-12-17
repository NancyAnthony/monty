#include "monty.h"
/**
 * mul_opcodes - multiplies the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void mul_opcodes(stack_t **head, unsigned int count)
{
	stack_t *tp;
	int size;
	int j;

	tp = *head;
	size = 0;
	while (tp)
	{
		tp = tp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	j = tp->next->n * tp->n;
	tp->next->n = j;
	*head = tp->next;
	free(tp);
}
