#ifndef MAIN_H
#define MAIN_H
#define MAX_LINE 1000 /* Maximum input line */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

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
 * optr - The handler for a specific operation
 * @stack: pointer to pointer to a stack
 * @line_num: current line number
 **/
typedef void (*operator)(stack_t **stack, unsigned int line_num);

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
	operator f;
} instruction_t;

void print_stack(stack_t *top);
stack_t *push_stack(stack_t **head, const int n);
void free_stack(stack_t *head);
operator get_op(char *s);
void run_op(stack_t **top, operator f, unsigned int, char *);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
size_t _getline(char s[], int lim, FILE *f);
size_t _dprintf(const int fd, const char *format, ...);

#endif
