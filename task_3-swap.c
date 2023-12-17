#include "monty.h"
/**
 * swap_opcodes - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void swap_opcodes(stack_t **head, unsigned int count)
{
	stack_t *tp;
	int size = 0;
	int temp;

	tp = *head;
	while (tp)
	{
		tp = tp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	temp = tp->n;
	tp->n = tp->next->n;
	tp->next->n = temp;
}
