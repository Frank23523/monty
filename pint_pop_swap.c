#include "monty.h"

/**
 * m_pint - Prints the top value of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		add_error_code(print_pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * m_pop - Removes the top value element of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		add_error_code(print_pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * m_swap - swaps the top two value elements of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
