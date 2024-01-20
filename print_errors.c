#include "monty.h"

/**
 * print_usage_error - prints error message when program is not run correctly.
 * Return: (EXIT_FAILURE) always.
 */
int print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * print_malloc_error - prints error message when malloc fails.
 * Return: (EXIT_FAILURE) always.
 */
int print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * print_open_error - Prints an error message when a file cannot be opened.
 * @filename: Name of the file that failed to open.
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * print_inst_error - prints error message after unknown instruction
 * @opcode: opcode that caused the error.
 * @line_number: line number
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_inst_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * print_invalid_error - prints error message for invalid argument.
 * @line_number: line number
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_invalid_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
