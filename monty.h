#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LINE 10000			/* Maximum input line */
#define ERR_C STDERR_FILENO /* Alias to STDERR_FILENO */

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * push_t - dynamic function
 */
typedef stack_t *push_t(stack_t **top, const int n);

/**
 * struct data_s - store data  to use across funcs
 * @run_status: 0 or -1
 * @elem: arg for command
 * @push_stack: handler to dynamically manage LIFO and FIFO push conditions
 */
typedef struct data_s
{
	char *elem;
	int run_status;
	/* handler to dynamically manage LIFO and FIFO push conditions */
	push_t *push_stack;
} data_t;

data_t data;

void print_stack(stack_t *top);
stack_t *push_stack(stack_t **head, const int n);
void free_stack(stack_t *head);
operator get_op(char *s);
void run_op(stack_t **top, operator f, unsigned int, char *);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

size_t _getline(char s[], int lim, FILE *f);
size_t _dprintf(const int fd, const char *format, ...);

void pop(stack_t **top, unsigned int line_num);
void pint(stack_t **top, unsigned int line_num);
void pchar(stack_t **top, unsigned int ln);
void pstr(stack_t **top, unsigned int ln);
void rotl(stack_t **top, unsigned int ln);
void rotr(stack_t **top, unsigned int ln);
stack_t *push_stack_end(stack_t **top, const int n);
void reverse_stack(stack_t **top);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);

size_t stack_len(const stack_t *h);
#endif
