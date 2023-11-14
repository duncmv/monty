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

	if (elem != NULL)
	{
	/*solution for edge case when elem is 0*/
		if (strcmp(elem, "0") == 0)
		{
			n = 0;
		}
		else
		{
			n = atoi(elem);
			if (n == 0)
			{
				dprintf(2, "L%d: usage: push integer\n", l);
				*(&run_status) = -1;
				return;
			}
		}
	}
	new = push_stack(stack, n);
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		*(&run_status) = -1;
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
