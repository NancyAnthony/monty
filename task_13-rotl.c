#include "monty.h"
/**
  *rotl_opcodes- rotates the stack to the top
  *@head: stack head
  *@count: line_number
  *Return: nothing
 */
void rotl_opcodes(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *tp = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (temp->next != NULL)
	{
		tp = tp->next;
	}
	tp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tp;
	(*head) = temp;
}
