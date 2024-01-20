#include "monty.h"

/**
 * m_add - adds the top two values of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_sub - subtracts 2nd value from top
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_div - divides 2nd value from the top
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		add_error_code(print_div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_mul - multiplies the 2nd value from the top
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_mod - Computes the modulus of 2nd value
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error_code(print_short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		add_error_code(print_div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	m_pop(stack, line_number);
}
