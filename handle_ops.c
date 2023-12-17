#include "monty.h"
/**
 * handle_ops - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @montyFile: poiner to monty file
 * @data: line content
 * Return: Nothing
 */
int handle_ops(char *data, stack_t **stack,
		unsigned int counter, FILE *montyFile)
{
	instruction_t ops[] = {
		{"push", push_opcodes}, {"pall", pall_opcodes},
		{"pint", pint_opcodes}, {"pop", pop_opcodes},
		{"swap", swap_opcodes}, {"add", add_opcodes},
		{"nop", nop_opcodes}, {"sub", sub_opcodes},
		{"div", div_opcodes}, {"mul", mul_opcodes},
		{"mod", mod_opcodes}, {"pchar", pchar_opcode},
		{"pstr", pstr_opcodes}, {"rotl", rotl_opcodes},
		{"rotr", rotr_opcodes}, {"queue", print_top},
		{"stack", stack_opcodes}, {NULL, NULL}
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
