#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#define UNUSED(x) (void)(x)
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @cmdArg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct programData
{
	char *cmdArg;
	FILE *montyFile;
	char *data;
	int modeFlag;
} programData_t;

extern programData_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_opcodes(stack_t **h, unsigned int count_line);
void handlePushError(programData_t bus, int counter, stack_t** head);
void inc_node(stack_t **head, int n);
void print_top(stack_t **head, unsigned int counter);
void inc_queue(stack_t **head, int n);
void pall_opcodes(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void pint_opcodes(stack_t **head, unsigned int count);
int handle_ops(char *data, stack_t **stack, unsigned int     counter, FILE *montyFile);
void pop_opcodes(stack_t **head, unsigned int count);
void stack_opcodes(stack_t **head, unsigned int count);
void add_opcodes(stack_t **head, unsigned int count);
void swap_opcodes(stack_t **head, unsigned int count);
void nop_opcodes(stack_t **head, unsigned int counter);
void sub_opcodes(stack_t **head, unsigned int count);
void div_opcodes(stack_t **head, unsigned int count);
void mul_opcodes(stack_t **head, unsigned int count);
void mod_opcodes(stack_t **head, unsigned int count);
void pchar_opcode(stack_t **head, unsigned int count);
void pstr_opcodes(stack_t **head, unsigned int count);
void rotl_opcodes(stack_t **head,  __attribute__((unused    )) unsigned int count);
void rotr_opcodes(stack_t **head, __attribute__((unused)    ) unsigned int count);
void stack_opcodes(stack_t **head, unsigned int count);


#endif
