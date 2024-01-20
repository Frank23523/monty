#include "monty.h"

/**
 * convert_num_to_base - converts a number to a string
 * @num: number to convert.
 * @base: base for conversion
 * @str: string buffer to store the result of the conversion.
 * @str_size: size of the string buffer in bytes.
 */
void convert_num_to_base(unsigned int num, unsigned int base,
		char *str, int str_size)
{
	int remainder, i = str_size - 1;

	str[str_size] = '\0';
	while (i >= 0)
	{
		remainder = num % base;
		if (remainder > 9)
			str[i] = remainder + 87;
		else
			str[i] = remainder + '0';
		num /= base;
		i--;
	}
}

/**
 * get_digits_in_base - gets number of digits
 * @num: number to convert.
 * @base: base to use for the conversion.
 *
 * Return: number of digits
 */
int get_digits_in_base(unsigned int num, unsigned int base)
{
	int num_digits = 1;

	while (num > base - 1)
	{
		num_digits++;
		num /= base;
	}
	return (num_digits);
}

/**
 * int_to_string - converts an integer to string.
 * @num: integer to convert
 *
 * Return: pointer to string
 */
char *int_to_string(int num)
{
	unsigned int abs_num;
	int num_digits = 0;
	long long_num = 0;
	char *str;

	abs_num = get_absolute_value(num);
	num_digits = get_digits_in_base(abs_num, 10);

	if (num < 0 || long_num < 0)
		num_digits++;

	str = malloc(num_digits + 1);
	if (str == NULL)
		return (NULL);

	convert_num_to_base(abs_num, 10, str, num_digits);
	if (num < 0 || long_num < 0)
		str[0] = '-';

	return (str);
}

/**
 * get_absolute_value - Gets the absolute value of an integer.
 * @i: integer to get the absolute value of.
 *
 * Return: absolute value
 */
unsigned int get_absolute_value(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
