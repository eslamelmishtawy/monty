#include "monty.h"

int data;
/**
 * main - function to check the operation
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fd = NULL;
	char **parsed_line, *line = NULL;
	size_t buff_size = 100;
	unsigned int line_number = 1;
	void (*func)(stack_t **stack, unsigned int line_num);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * buff_size);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &buff_size, fd) != -1)
	{
		parsed_line = tokenizer(line);
		func = check_opcodes(parsed_line[0]);
		if (parsed_line[1] != NULL)
			data = atoi(parsed_line[1]);
		func(&stack, line_number);
		line_number++;
	}
	return (0);

}

/**
 * check_opcodes - function to check the operation
 * @op: parsed_line
 * Return: pointer to function
 */

void (*check_opcodes(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (strcmp(op, instruct[i].opcode) == 0)
		{
			return (instruct[i].f);
		}
		i++;
	}
	return (0);
}
