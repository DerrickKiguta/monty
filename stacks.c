#include "monty.h"
#include <string.h>

void free_stack_unique(stack_t **stack);
int init_stack_unique(stack_t **stack);
int check_mode_unique(stack_t *stack);

/**
 * free_stack_unique - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack_unique(stack_t **stack)
{
	stack_t *tmp_unique = *stack;

	while (*stack)
	{
		tmp_unique = (*stack)->next;
		free(*stack);
		*stack = tmp_unique;
	}
}

/**
 * init_stack_unique - Initializes a stack_t stack with beginning
 *                     stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack_unique(stack_t **stack)
{
	stack_t *s_unique;

	s_unique = malloc(sizeof(stack_t));
	if (s_unique == NULL)
		return (malloc_error_unique());

	s_unique->n = STACK_UNIQUE;
	s_unique->prev = NULL;
	s_unique->next = NULL;

	*stack = s_unique;

	return (EXIT_SUCCESS);
}

/**
 * check_mode_unique - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK_UNIQUE (0).
 *         If the stack_t is in queue mode - QUEUE_UNIQUE (1).
 *         Otherwise - 2.
 */
int check_mode_unique(stack_t *stack)
{
	if (stack->n == STACK_UNIQUE)
		return (STACK_UNIQUE);
	else if (stack->n == QUEUE_UNIQUE)
		return (QUEUE_UNIQUE);
	return (2);
}
