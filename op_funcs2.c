#include "main.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack top
 * @line_num: line number of the operation
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_num)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		_dprintf(ERR_C, "L%d: can't pop an empty stack", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *top;	     /* assign top to a variable */
	*top = (*top)->next; /* rename *top to *top.next */
	(*top)->prev = NULL; /* disconnect the prev of *top */
	tmp->next = NULL;    /* disconect the next of the variable */
	tmp->prev = NULL;    /* not really needed */
	free(tmp);	     /* free the variable */
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the stack top
 * @line_num: line number of the operation
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_num)
{
	if (*top == NULL)
	{
		_dprintf(ERR_C, "L%d: can't pint, stack empty", line_num);
		exit(EXIT_FAILURE);
	}
	/* print the top item */
	printf("%d\n", (*top)->n);
}
