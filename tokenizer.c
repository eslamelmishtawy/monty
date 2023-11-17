#include "monty.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = (char *)malloc((sizeof(char) * len) + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';

	return (copy);
}

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
	tmp = _strdup(str);
	token = strtok(tmp, " \t\n");

	if (!token)
	{
		free(tmp);
		free(str);
		return (NULL);
	}
	list_str = malloc(sizeof(char *) * (index + 1));
	if (!list_str)
	{
		free(list_str);
		free(str);
		return (NULL);
	}
	while (token)
	{
		list_str[index] = _strdup(token);
		token = strtok(NULL, " \n\t");
		index++;
	}
	list_str[index] = NULL;
	return (list_str);
}
