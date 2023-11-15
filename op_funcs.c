#include "main.h"

/**
 * push - pushes to stack
 * @stack: top of stack
 * @line_number: op line
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, l = (int)line_number;
	stack_t *new;

	if (data.elem != NULL)
	{
		/*solution for edge case when data.elem is 0*/
		if (strcmp(data.elem, "0") == 0)
		{
			n = 0;
		}
		else
		{
			n = atoi(data.elem);
			if (n == 0)
			{
				_dprintf(2, "L%d: usage: push integer\n", l);
				*(&data.run_status) = -1;
				return;
			}
		}
	}
	new = push_stack(stack, n);
	if (new == NULL)
	{
		_dprintf(2, "Error: malloc failed\n");
		*(&data.run_status) = -1;
	}
}
/**
 * pall - prints values of stack
 * @stack: top of stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_stack(*stack);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: top of stack
 * @line_number: lune number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		_dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}
	
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * add - adds the top two elements on the stack
 * @stack: top of stack
 * @line_number: line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		_dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: top of stack
 * @line_number: line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
