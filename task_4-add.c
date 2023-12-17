#include "monty.h"
/**
 * add_opcodes - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void add_opcodes(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int size = 0;
	int tp;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	tp = temp->n + temp->next->n;
	temp->next->n = tp;
	*head = temp->next;
	free(temp);
}
