#include "main.h"
/**
 * print_stack - prints all elements of the stack
 * @top: top of the stack
 */
void print_stack(stack_t *top)
{
	if (top != NULL)
	{
		printf("%d\n", top->n);
		print_dlistint(h->next);
	}
}
/**
 * push_stack - adds a new element to stack
 * @head: double pointer to top of stack
 * @n: int to be added as member of node
 * Return: address of new node
 */
stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new = (stack_t *)malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

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
