#include "monty.h"

/**
 * get_toks_len - gets number of elements in op_toks array.
 *
 * Return: number of elements
 */
unsigned int get_toks_len(void)
{
	unsigned int i = 0;

	while (op_toks[i])
		i++;
	return (i);
}

/**
 * free_op_toks - frees memory allocated for the op_toks array of strings.
 */
void free_op_toks(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * is_line_empty - checks if line read from getline only contains delimiters.
 * @line: line.
 * @delimiters: delimiters
 *
 * Return: 1 if delimeters, else 0
 */
int is_line_empty(char *line, char *delimiters)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (line[i] == delimiters[j])
				break;
		}
		if (delimiters[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * get_opcode_function - matches an opcode with its corresponding function.
 * @opcode: opcode to match.
 *
 * Return: corresponding function.
 */
void (*get_opcode_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * execute_monty_script - executes a Monty bytecodes script.
 * @script_fd: file descriptor
 *
 * Return: EXIT_SUCCESS on success, or the respective error code on failure.
 */
int execute_monty_script(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_length = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, previous_token_count = 0;
	void (*opcode_function)(stack_t**, unsigned int);

	if (create_stack_list(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &line_length, script_fd) != -1)
	{
		line_number++;
		op_toks = split_string(line, DELIMITERS);
		if (op_toks == NULL)
		{
			if (is_line_empty(line, DELIMITERS))
				continue;
			free_stack_list(&stack);
			return (print_malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_op_toks();
			continue;
		}
		opcode_function = get_opcode_function(op_toks[0]);
		if (opcode_function == NULL)
		{
			free_stack_list(&stack);
			exit_status = print_inst_error(op_toks[0], line_number);
			free_op_toks();
			break;
		}
		previous_token_count = get_toks_len();
		opcode_function(&stack, line_number);
		if (get_toks_len() != previous_token_count)
		{
			if (op_toks && op_toks[previous_token_count])
				exit_status = atoi(op_toks[previous_token_count]);
			else
				exit_status = EXIT_FAILURE;
			free_op_toks();
			break;
		}
		free_op_toks();
	}
	free_stack_list(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (print_malloc_error());
	}
	free(line);
	return (exit_status);
}
