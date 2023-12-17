#include "monty.h"
/**
 * mod_opcodes - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void mod_opcodes(stack_t **head, unsigned int count)
{
	stack_t *tp;
	int size;
	int tmp;

	tp = *head;
	while (tp)
	{
		tp = tp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	if (tp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = tp->next->n % tp->n;
	tp->next->n = tmp;
	*head = tp->next;
	free(tp);
}
