#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/**
	* struct stack_s - doubly linked list representation of a stack (or queue)
	* @n: integer
	* @prev: points to the previous element of the stack (or queue)
	* @next: points to the next element of the stack (or queue)
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
	* struct instruction_s - opcode and its function
	* @opcode: the opcode
	* @f: function to handle the opcode
	* Description: opcode and its function
	* for stack, queues, LIFO, FIFO
	*/
typedef struct instruction_s
{
	char *opcode;
	void (*fptr)(stack_t **stack, unsigned int line_number, char **arrcmd);
} instruction_t;

char **getln_split(stack_t **elements);
int interpreter(char **arraycmd, stack_t **elements, unsigned int line_number);
void push(stack_t **elements, unsigned int line_number, char **arrcmd);
void pall(stack_t **elements, unsigned int ln_num, char **arrcmd);
void pop(stack_t **elements, unsigned int ln_num, char **arrcmd);
void freelist(stack_t **elements, char **arrcmd);
void bad_malloc(stack_t **elements, char **arrcmd);

extern instruction_t opcodelist[];

#define OPCODE_LEN 3

#endif
