#include "monty.h"

/**
 * m_rotl - rotates the top value of a stack_t linked list to the bottom.
 * @stack: pointer to the top of the stack.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * m_rotr - rotates the bottom value of a stack_t linked list to the top.
 * @stack: pointer to the top of the stack.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * m_stack - converts a queue to a stack.
 * @stack: pointer to the top of the stack.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * m_queue - converts a stack to a queue.
 * @stack: pointer to the top of the stack.
 * @line_number: line number of a Monty bytecodes file.
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
