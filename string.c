#include "monty.h"

/**
 * split_string - splits string into array
 * @str: string to split.
 * @delimiters: delimiters to use to split the string.
 *
 * Return: A 2D array of pointers to each word in the string.
 */
char **split_string(char *str, char *delimiters)
{
	char **words = NULL;
	int num_words, word_len, i = 0, j;

	if (str == NULL || !*str)
		return (NULL);

	num_words = get_num_words(str, delimiters);
	if (num_words == 0)
		return (NULL);

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (i < num_words)
	{
		word_len = get_word_length(str, delimiters);
		if (is_delimiter(*str, delimiters))
			str = get_next_word(str, delimiters);

		words[i] = malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (j = 0; j < word_len; j++)
			words[i][j] = *(str + j);
		words[i][j] = '\0';
		str = get_next_word(str, delimiters);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delimiter - checks if a character is a delimiter.
 * @ch: character to check.
 * @delimiters: A pointer to a null-terminated array of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delimiter(char ch, char *delimiters)
{
	int i = 0;

	while (delimiters[i])
	{
		if (delimiters[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Gets the length of the current word in a string.
 * @str: The string to get the word length from.
 * @delimiters: The delimiters to use to delimit words.
 *
 * Return: The length of the current word in the string.
 */
int get_word_length(char *str, char *delimiters)
{
	int word_length = 0, next_word = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
			next_word = 1;
		else if (next_word)
		{
			word_length++;
		}
		if (word_length > 0 && is_delimiter(str[i], delimiters))
			break;
		i++;
	}
	return (word_length);
}

/**
 * get_num_words - gets number of words in a string.
 * @str: string
 * @delimiters: delimiters
 *
 * Return: number of words
 */
int get_num_words(char *str, char *delimiters)
{
	int num_words = 0, next_word = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
			next_word = 1;
		else if (next_word)
		{
			next_word = 0;
			num_words++;
		}
		i++;
	}
	return (num_words);
}

/**
 * get_next_word - gets first character of next word in a string.
 * @str: string
 * @delimiters: delimiters
 *
 * Return: first character
 */
char *get_next_word(char *str, char *delimiters)
{
	int next_word = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
			next_word = 1;
		else if (next_word)
			break;
		i++;
	}
	return (str + i);
}
