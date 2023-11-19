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
/**
 * _pop - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
        if (*stack == NULL)
        {
                free_stack(*stack);
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
                exit(EXIT_FAILURE);
        }
        *stack= (*stack)->prev;
	free(tmp);

}
/**
 * _swap - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	int tmp = (*stack)->n;
	int i = 0;
	stack_t *temp = NULL;
	
	temp = *stack;

	for (; temp != NULL; temp = temp->prev, i++)
		;
        if (i < 2)
        {
                free_stack(*stack);
                free_stack(temp);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }
	(*stack)->n = ((*stack)->prev)->n;
	((*stack)->prev)->n = tmp;

}
/**
 * _add - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _add(stack_t **stack, unsigned int line_num)
{
        int tmp = (*stack)->n;
        int i = 0;
        stack_t *temp = NULL;

	temp = *stack;
        for (; temp != NULL; temp= temp->prev, i++)
                ;
        if (i < 2)
        {
		free_stack(temp);
                free_stack(*stack);
                fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }
	temp = *stack;
	*stack= (*stack)->prev;
	(*stack)->n += tmp;
	free(temp);
}
/**
 * _nop - Print stack
 * @stack: pointer to head of stack
 * @line_num: line num
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
