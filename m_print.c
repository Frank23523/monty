#include "monty.h"

/**
 * m_nop - does nothing
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * m_pchar - prints character in the top value
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		add_error_code(print_pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		add_error_code(print_pchar_error(line_number,
					"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * m_pstr - prints string contained in a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack)->next;

	while (current && current->n != 0 && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");

	(void)line_number;
}
