#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *s = *stack;

	if (!stack)
	{
		free_stack(*stack);
		free_stack(s);
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}

	s = malloc(sizeof(stack_t));
	if (!s)
	{
		free_stack(s);
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
	(void) line_num;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
}
