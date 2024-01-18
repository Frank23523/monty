#include "monty.h"

/**
 * _pall -  prints all the values on the stack
 * @stack: head
 * @line_number: unused
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * _push -  pushes an element to the stack
 * @stack: the stack
 * @num: integer to be pushed
 * @line_number: line number
 */
void _push(stack_t **stack, int num, unsigned int line_number)
{
	stack_t *new_node, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		head->prev = new_node;

	*stack = new_node;
}

/**
 * _pop - Removes the top element from the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head != NULL)
	{
		*stack = head->next;
		free(head);
	}
}

/**
 * _swap - Swaps the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *ele2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head && head->next)
	{
		ele2 = head->next;
		if (ele2->next)
			ele2->next->prev = head;

		head->next = ele2->next;
		ele2->prev = NULL;
		ele2->next = head;
		head->prev = ele2;
		*stack = ele2;
	}
}
