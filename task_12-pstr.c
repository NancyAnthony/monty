#include "monty.h"
/**
 * pstr_opcodes - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void pstr_opcodes(stack_t **head, unsigned int count)
{
	stack_t *tp;

	UNUSED(count);
	tp = *head;
	while (tp)
	{
		if (tp->n > 127 || tp->n <= 0)
		{
			break;
		}
		printf("%c", tp->n);
		tp = tp->next;
	}
	printf("\n");
}
