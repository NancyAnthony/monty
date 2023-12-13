#include "monty.h"

void push(unsigned int value, stack_t **stack)
{
stack_t *new_node;

new_node = (stack_t *)malloc(sizeof(stack_t));
if (new_node == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

new_node->prev = NULL;
new_node->n = n;
new_node->next = NULL;

new_node->prev = *stack;
*stack = new_node;

}
