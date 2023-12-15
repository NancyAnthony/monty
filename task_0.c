#include "monty.h"
/**
 * handlePushError - Handles the push error
 * @bus:
 * @counter: count line number
 * @head: pointer to the first node
 * Return: nothing
 */

void handlePushError(programData_t bus, int counter, stack_t** head) 
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(bus.montyFile);
	free(bus.data);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * push_opcodes - add node to the stack
 * @head: stack head
 * @count_line: line_number
 * Return: Nothing
 */
void push_opcodes(stack_t **head, unsigned int count_line)
{
	int num, ind = 0, errorFlag = 0;

	if (bus.cmdArg)
	{
		if (bus.cmdArg[0] == '-')
			ind++;
		for (; bus.cmdArg[ind] != '\0'; ind++)
		{
			if (!isdigit(bus.cmdArg[ind]))
				errorFlag = 1; }
		if (errorFlag == 1)
		{
			handlePushError(bus, count_line, head);
		}
	}
	else
	{
		handlePushError(bus, count_line, head);
	}
	num = atoi(bus.cmdArg);
	if (bus.modeFlag == 0)
		inc_node(head, num);
	else
		inc_queue(head, num);
}

#include "monty.h"
/**
 * pall_opcodes - prints the stack
 * @head: stack head
 * @counter: counts the number of nodes
 * Return: Nothing
 */
void pall_opcodes(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		return;
}
	for (counter = 0; tmp != NULL; counter++)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
