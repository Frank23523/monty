#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *str[1000] = {NULL};
	int i = 0;
	FILE *fd;
	size_t buffer = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(str[i]), &buffer, fd) > 0)
		i++;

	execute_inst(str, stack);
	free_strArray(str);
	fclose(fd);

	return (0);
}

/**
 * execute_inst - Executes Monty opcodes
 * @str: Contents of the file
 * @stack: list
 */
void execute_inst(char *str[], stack_t *stack)
{
	int line_number, num, i;

	instruction_t inst[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"nop", nop},
		{"null", NULL}
	};

	for (line_number = 1, num = 0; str[num + 1]; num++, line_number++)
	{
		if (_strcmp("push", str[num]))
			push(&stack, line_number, extract(str[num], line_number));
		else if (_strcmp("nop", str[num]))
			;
		else
		{
			i = 0;
			while (_strcmp(inst[i].opcode, "null"))
			{
				if (_strcmp(inst[i].opcode, str[num]))
				{
					inst[i].f(&stack, line_number);
					break;
				}
				i++;
			}
			if (_strcmp(inst[i].opcode, "null") && !_strcmp(str[num], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_number, str[num]);
				if (!find_newline(str[num]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	freeStack(stack);
}
