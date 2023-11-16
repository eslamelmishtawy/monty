#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * @n: variable
 */
void _push(stack_t **stack, unsigned int line_num, int n)
{
	if (!stack)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	stack_t *s = *stack;
	stack_t *temp = *stack;

	s = malloc(sizeof(stack_t));
	if (!s)
		exit(EXIT_FAILURE);
	s->n = n;
	s->next = NULL;
	s-prev = *stack;
	*stack = s;
}

/**
 * _pall - Print stack
 * @stack: pointer to head of stack
 */
void _pall(stack_t *stack)
{
	while (stack)
	{
		printf("%d", stack->n);
		stack = stack->prev;
	}
}
