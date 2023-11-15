#include "monty.h"
#include <ctype.h>

/**
 * pop - removes the top element of the stack
 * @top: double pointer to the stack top
 * @line_num: line number of the operation
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_num)
{
	stack_t *tmp;

	if (stack_len(*top) == 0)
	{
		_dprintf(ERR_C, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *top;	     /* assign top to a variable */
	*top = (*top)->next; /* rename *top to *top.next */
	if (*top != NULL)
		(*top)->prev = NULL; /* disconnect the prev of *top */

	tmp->next = NULL; /* disconect the next of the variable */
	tmp->prev = NULL; /* not really needed */
	free(tmp);	  /* free the variable */
}

/**
 * pchar -  prints the char at the top of the stack
 * @top: double pointer to the stack top
 * @ln: line number of the operation
 *
 * Return: void
 */
void pchar(stack_t **top, unsigned int ln)
{

	if (stack_len(*top) == 0)
	{
		_dprintf(ERR_C, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n < 0 || (*top)->n > 127)
	{
		_dprintf(ERR_C, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * pint - prints the value at the top of the stack
 * @top: double pointer to the stack top
 * @line_num: line number of the operation
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_num)
{
	if (stack_len(*top) == 0)
	{
		_dprintf(ERR_C, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	/* print the top item */
	printf("%d\n", (*top)->n);
}

/**
 * pstr -  prints the string starting at the top of the stack
 * @top: double pointer to the stack top
 * @ln: line number of the operation
 *
 * Return: void
 */
void pstr(stack_t **top, unsigned int ln)
{
	stack_t *t;

	(void)ln;
	for (t = *top; t && t->n > 0 && t->n <= 127; t = t->next)
		putchar('0' + (*top)->n);
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @top: double pointer to the top
 * @ln: line number of the operation
 *
 * Return: void
 */
void rotl(stack_t **top, unsigned int ln)
{
	stack_t *t, *last;
	unsigned int len;

	(void)ln;
	for (len = 0, t = *top; t; len++, t = t->next)
		last = t;
	if (len < 2)
		return;
	/* push top to the last and last to the top */
	t = *top;
	last->next = t->next;
	t->prev = last->prev;
	t->next = NULL;
	last->prev = NULL;
	*top = last;
}

/**
 * rotr - rotates the stack to the bottom
 * @top: double pointer to the top
 * @ln: line number of the operation
 *
 * Return: void
 * The last element of the stack becomes the top element of the stack
 */
void rotr(stack_t **top, unsigned int ln)
{
	stack_t *t, *last;

	(void)ln;
	if (stack_len(*top) < 2)
		return;
	for (t = *top; t; t = t->next)
		last = t;
	/* make the last element to be the top */
	last->next = *top;
	last->prev->next = NULL;
	last->prev = NULL;
	(*top)->prev = last;
	*top = last;
}
