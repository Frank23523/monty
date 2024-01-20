#include "monty.h"

/**
 * add_error_code - Adds an error code to the end of op_toks array.
 * @error_code: integer to store as a string in op_toks.
 */
void add_error_code(int error_code)
{
	int num_tokens = 0, i = 0;
	char *error_str = NULL;
	char **new_op_toks = NULL;

	/* Get the number of tokens in the op_toks array */
	num_tokens = get_toks_len();
	/* Allocate memory for a new array with one extra element */
	new_op_toks = malloc(sizeof(char *) * (num_tokens + 2));
	if (op_toks == NULL)
	{
		print_malloc_error();
		return;
	}
	/* Copy the existing tokens to the new array */
	while (i < num_tokens)
	{
		new_op_toks[i] = op_toks[i];
		i++;
	}
	/* Convert the error code to a string */
	error_str = int_to_string(error_code);
	if (error_str == NULL)
	{
		print_malloc_error();
		return;
	}
	/* Add the error code string to the end of the new array */
	new_op_toks[i++] = error_str;
	new_op_toks[i] = NULL;
	/* Free the old array and assign the new one to op_toks */
	free(op_toks);
	op_toks = new_op_toks;
}
