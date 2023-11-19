#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *s = *stack;

	(void) line_num ;
	s = malloc(sizeof(stack_t));
	if (!s)
	{
		free(s);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	s->n = data;
	s->next = NULL;
	s->prev = *stack;
	*stack = s;
}

/**
 * _pall - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void) line_num;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * _pint - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
