#include "main.h"

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
*
* Return: Always 0 (success)
*/
int _strcmp(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		if (*s2 == ' ')
			s2++;
		else if (*s1 == *s2)
		{
			s1++;
			s2++;
			if (*s1 == '\0' && (*s2 == ' ' || *s2 == '\n' || *s2 == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * find_newline - Finds newline character
 * @str: String to find '\n'
 * Return: 1 if newline is found, 0 otherwise
 */
int find_newline(char *str)
{
	char *newline = "\n";

	while (*str != '\0')
	{
		if (*newline == *str)
		{
			newline++;
			str++;
			if (*newline == '\0')
				return (1);
		}
		else
			str++;
	}
	return (0);
}

/**
 * f_combination - Finds non-numbers and number combinations
 * @str: string
 * @line_number: line number
 * Return: 1
 */
int f_combination(char *str, int line_number)
{
	int i = 1;

	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n')
			break;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * extract - Extracts an integer for the push opcode
 * @str: Content of the file
 * @line_number: Line number
 * Return: extracted integer
 */
int extract(char *str, int line_number)
{
	char *opcode = "push";

	while (*str != '\0')
	{
		if (*opcode == *str)
		{
			opcode++;
			str++;
			if (*opcode == '\0')
				while (*str)
				{
					if ((*str >= '0' && *str <= '9') || *str == '-')
					{
						f_combinstion(str, line_number);
						return (atoi(str));
					}
					else if (*str == ' ')
						str++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			str++;
	}
	return (0);
}
