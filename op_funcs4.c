#include "monty.h"

/**
 * queue - resets the stack to use FIFO
 * @stack: double pointer to the top
 * @line_number: line number of the operation
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (data.push_stack != push_stack_end)
	{
		data.push_stack = push_stack_end;
		(void)stack;
		/* reverse_stack(stack); */
	}
}

/**
 * stack - resets the stack to use LIFO
 * @stack: double pointer to the top
 * @line_number: line number of the operation
 *
 * Return: void
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	if (data.push_stack != push_stack)
	{
		data.push_stack = push_stack;
		/* reverse_stack(stack); */
	}
}
