#include "monty.h"
/**
 * print_stack - prints all elements of the stack
 * @top: top of the stack
 */
void print_stack(stack_t *top)
{
	if (top != NULL)
	{
		printf("%d\n", top->n);
		print_stack(top->next);
	}
}

/**
 * push_stack_end - adds a new element at the end of the stack
 * @top: double pointer to top of stack
 * @n: int to be added as member of node
 *
 * Return: address of new node
 */
stack_t *push_stack_end(stack_t **top, const int n)
{
	stack_t *new, *t, *last;
	unsigned int len;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	new->next = NULL;

	for (len = 0, t = *top; t; t = t->next, len++)
		last = t; /* Locate the last element */
	if (len == 0)
		*top = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
	return (new);
}

/**
 * push_stack - adds a new element to stack
 * @top: double pointer to top of stack
 * @n: int to be added as member of node
 *
 * Return: address of new node
 */
stack_t *push_stack(stack_t **top, const int n)
{
	stack_t *new = (stack_t *)malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	new->next = *top;
	if (*top != NULL)
		(*top)->prev = new;
	*top = new;

	return (new);
}
/**
 * free_stack - frees stack
 * @head: pointer to top of stack
 */
void free_stack(stack_t *head)
{
	if (head != NULL)
	{
		free_stack(head->next);
		free(head);
		head = NULL;
	}
}
/**
 * stack_len - return number of elements in stack
 * @h: top of the stack
 * Return: number of elem
 */
size_t stack_len(const stack_t *h)
{
	size_t i = 0;

	if (h != NULL)
	{
		i++;
		i += stack_len(h->next);
	}
	return (i);
}
