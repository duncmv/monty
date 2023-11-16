#include "monty.h"

/**
 * reverse_stack - flips the stack from top to bottom for each call
 * @top: double pointer to the top of the stack
 *
 * Return: void
 */
void reverse_stack(stack_t **top)
{
	stack_t *prev, *ref, *next;

	if (*top == NULL || (*top)->next == NULL)
		return;

	/* Below we flip the list in place from top to bottom */
	ref = *top;
	next = prev = (*top)->next; /* move prev & next a step forward */
	ref->next = NULL;	    /* This is the next of last element */
	ref->prev = next;
	while (prev)
	{
		next = next->next; /* move next forward */
		prev->next = ref;
		prev->prev = next;
		ref = prev;
		prev = next;
	}
}
