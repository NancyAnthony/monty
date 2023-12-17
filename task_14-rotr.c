#include "monty.h"
/**
 * rotr_opcodes- rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotr_opcodes(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *cpy;
	int i;

	cpy = *head;
	i = 0;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	for (i = 0; cpy->next; i++)
	{
		cpy = cpy->next;
	}
	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head)->prev = cpy;
	(*head) = cpy;
}
