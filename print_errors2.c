#include "monty.h"

/**
 * print_pop_error - Prints an error message when pop on empty stack.
 * @line_number: The line number in the script where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * print_pint_error - Prints an error message when pint an empty stack.
 * @line_number: line number in the Monty bytecodes file
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * print_short_stack_error - prints an error message on less than two nodes.
 * @line_number: line number in the Monty bytecodes file
 * @operation: The operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_short_stack_error(unsigned int line_number, char *operation)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, operation);
	return (EXIT_FAILURE);
}

/**
 * print_div_error - prints an error message when dividing by zero.
 * @line_number: line number in the Monty bytecodes file
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * print_pchar_error - prints an error message on pchar
 * @line_number: line number in the Monty bytecodes file
 * @message: corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
