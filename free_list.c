#include "monty.h"
/**
 * free_list - frees getline list
 * @a: pointer to array of strings
 * Return: Nothing
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
