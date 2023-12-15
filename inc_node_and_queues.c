#include "monty.h"
/**
 * inc_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void inc_node(stack_t **head, int n)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (temp)
	{
		temp->prev = new_node;
	}
	new_node->next = *head;
	*head = new_node;
}


/**
 * print_top - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void print_top(stack_t **head, unsigned int counter)
{
	UNUSED(head);
	UNUSED(counter);
	bus.modeFlag = 1;
}

/**
 * inc_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: nothing
 */
void inc_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
