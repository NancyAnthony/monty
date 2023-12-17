#include "monty.h"
/**
 *sub_opcodes- subtraction
 *@head: stack head
 *@count: line_number counter
 *Return: nothing
 */
void sub_opcodes(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int minus;
	int j;

	temp = *head;

	for (j = 0; temp != NULL; j++)
		temp = temp->next;
	if (j < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	minus = temp->next->n - temp->n;
	temp->next->n = minus;
	*head = temp->next;
	free(temp);
}
