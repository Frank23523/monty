#include "monty.h"

/**
 * freeStack - Frees a singly linked list
 * @head: Pointer to the head of the list
 * Return: Nothing
 */
void freeStack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

/**
 * free_strArray - Frees an array of strings
 * @strArray: Pointer to an array of strings
 * Return: Nothing
 */
void free_strArray(char *strArray[])
{
	int i = 0;

	while (strArray[i] != NULL)
	{
		free(strArray[i]);
		i++;
	}
}
