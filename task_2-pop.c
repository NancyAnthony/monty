#include "monty.h"
/**
 * pop_opcodes( - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void pop_opcodes(stack_t **head, unsigned int count)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.montyFile);
		free(bus.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);}
