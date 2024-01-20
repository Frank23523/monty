#include "monty.h"

/**
 * get_mode - gets the mode of a stack_t linked list
 * @head: head
 *
 * Return: 0 in stack mode, 1 in queue mode, 2 otherwise
 */
int get_mode(stack_t *head)
{
	/* Check the value of the head node to determine the mode */
	if (head->n == STACK)
		return (STACK);
	else if (head->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * free_stack_list - frees memory allocated for a stack_t linked list.
 * @stack: head node of a stack_t linked list.
 */
void free_stack_list(stack_t **stack)
{
	stack_t *current = *stack;

	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
}

/**
 * create_stack_list - creates stack_t linked list
 * @stack: unitialized stack_t linked list.
 *
 * Return: EXIT_SUCCESS on success, else EXIT_FAILURE
 */
int create_stack_list(stack_t **stack)
{
	stack_t *head;

	head = malloc(sizeof(stack_t));
	if (head == NULL)
		return (print_malloc_error());

	/* Set the head node value to STACK and the pointers to NULL */
	head->n = STACK;
	head->prev = NULL;
	head->next = NULL;

	*stack = head;

	return (EXIT_SUCCESS);
}
