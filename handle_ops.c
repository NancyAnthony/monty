#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @montyFile: poiner to monty file
 * @data: line content
 * Return: Nothing
 */
int handle_ops(char *data, stack_t **stack, unsigned int counter, FILE *montyFile)
{
	instruction_t ops[] = {
		{"push", push_opcodes},
		{"pall", pall_opcodes},
		/*{"pint", f_pint},*/
		/*{"pop", f_pop},*/
		/*{"swap", f_swap},*/
		/*{"add", f_add},*/
		/*{"nop", f_nop},*/
		/*{"sub", f_sub},*/
		/*{"div", f_div},*/
		/*{"mul", f_mul},*/
		/*{"mod", f_mod},*/
		/*{"pchar", f_pchar},*/
		/*{"pstr", f_pstr},*/
		/*{"rotl", f_rotl},*/
		/*{"rotr", f_rotr},*/
		/*{"queue", f_queue},*/
		/*{"stack", f_stack},*/
		{NULL, NULL}
	};
	unsigned int ind = 0;
	char *opcodes;

	opcodes = strtok(data, " \n\t");
	if (opcodes && opcodes[0] == '#')
	{
		return (0);
	}
	bus.cmdArg = strtok(NULL, " \n\t");
	for (; ops[ind].opcode && opcodes; ind++)
	{
		if (strcmp(opcodes, ops[ind].opcode) == 0)
		{	ops[ind].f(stack, counter);
			return (0);
		}
	}
	if (opcodes && ops[ind].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcodes);
		fclose(montyFile);
		free(data);
		free_stack(*stack);
		exit(EXIT_FAILURE); 
	}
	return (1);
}
