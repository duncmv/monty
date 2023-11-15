#include "monty.h"
/**
 * sub - subtracts the top two elements on the stack
 * @stack: top of stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		_dprintf(ERR_C, "L%d: can't sub, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div - divides the top two elements on the stack
 * @stack: top of stack
 * @line_number: line number
 */
void divi(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		_dprintf(ERR_C, "L%d: can't div, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}
        if ((*stack)->n == 0)
        {
                _dprintf(ERR_C, "L%d: division by zero\n", line_number);
		*(&data.run_status) = -1;
		return;
        }
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mul - multiplies the top two elements on the stack
 * @stack: top of stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		_dprintf(ERR_C, "L%d: can't mul, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}

	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mod - adds the top two elements on the stack
 * @stack: top of stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		_dprintf(ERR_C, "L%d: can't mod, stack too short\n", line_number);
		*(&data.run_status) = -1;
		return;
	}
        if ((*stack)->n == 0)
        {
                _dprintf(ERR_C, "L%d: division by zero\n", line_number);
		*(&data.run_status) = -1;
		return;
        }
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}