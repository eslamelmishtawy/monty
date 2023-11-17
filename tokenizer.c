#include "monty.h"
/**
 * tokenizer - breaks string in to array of strings
 * @str: line entered from the terminal
 * Return: list of strings from the entered line
 */


char **tokenizer(char *str)
{
	char **list_str = NULL;
	char *tmp = NULL;
	char *token = NULL;
	int index = 0;

	if (!str)
		return (NULL);
	tmp = strdup(str);
	token = strtok(tmp, " \t\n");

	if (!token)
	{
		free(tmp);
		free(str);
		return (NULL);
	}
	while (token)
	{
		index++;
		token = strtok(NULL, " \n\t");
	}
	free(tmp);
	list_str = malloc(sizeof(char *) * (index + 1));
	if (!list_str)
	{
		free(str);
		return (NULL);
	}
	index = 0;
	token = strtok(str, " \n\t");
	while (token)
	{
		list_str[index] = strdup(token);
		token = strtok(NULL, " \n\t");
		index++;
	}
	list_str[index] = NULL;
	return (list_str);
}
