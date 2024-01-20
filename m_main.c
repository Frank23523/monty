#include "monty.h"

char **op_toks = NULL;
/**
 * main - the entry point for Monty Interp
 * @argc: argument count
 * @argv: argument vector
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (print_usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (print_open_error(argv[1]));
	exit_code = execute_monty_script(script_fd);
	fclose(script_fd);
	return (exit_code);
}
