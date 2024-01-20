#include "monty.h"

/**
 * m_push - pushes an element to the top or end of a stack
 * @stack: head
 * @line_number: line number
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		add_error_code(print_malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		add_error_code(print_invalid_error(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			add_error_code(print_invalid_error(line_number));
			return;
		}
	}
	new_node->n = atoi(op_toks[1]);
	if (get_mode(*stack) == STACK)
	{
		current = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = current;
		if (current)
			current->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		new_node->prev = current;
		new_node->next = NULL;
		current->next = new_node;
	}
}

/**
 * m_pall - prints the values of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = (*stack)->next;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
	(void)line_number;
}
