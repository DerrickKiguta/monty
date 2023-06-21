#include "monty.h"
#include <string.h>

void free_tokens_unique(void);
unsigned int token_arr_len_unique(void);
int is_empty_line_unique(char *line, char *delims);
void (*get_op_func_unique(char *opcode))(stack_t**, unsigned int);
int run_monty_unique(FILE *script_fd);

/**
 * free_tokens_unique - Frees the global op_toks array of strings.
 */
void free_tokens_unique(void)
{
	size_t i = 0;

	if (op_toks_unique == NULL)
		return;

	for (i = 0; op_toks_unique[i]; i++)
		free(op_toks_unique[i]);

	free(op_toks_unique);
}

/**
 * token_arr_len_unique - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len_unique(void)
{
	unsigned int toks_len = 0;

	while (op_toks_unique[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line_unique - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line_unique(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func_unique - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func_unique(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty_unique - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty_unique(FILE *script_fd)
{
	stack_t *stack_unique = NULL;
	char *line_unique = NULL;
	size_t len_unique = 0, exit_status_unique = EXIT_SUCCESS;
	unsigned int line_number_unique = 0, prev_tok_len_unique = 0;
	void (*op_func_unique)(stack_t**, unsigned int);

	if (init_stack(&stack_unique) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line_unique, &len_unique, script_fd) != -1)
	{
		line_number_unique++;
		op_toks_unique = strtow(line_unique, DELIMS);
		if (op_toks_unique == NULL)
		{
			if (is_empty_line_unique(line_unique, DELIMS))
				continue;
			free_stack(&stack_unique);
			return (malloc_error_unique());
		}
		else if (op_toks_unique[0][0] == '#') /* comment line */
		{
			free_tokens_unique();
			continue;
		}
		op_func_unique = get_op_func_unique(op_toks_unique[0]);
		if (op_func_unique == NULL)
		{
			free_stack(&stack_unique);
			exit_status_unique = unknown_op_error_unique(op_toks_unique[0], line_number_unique);
			free_tokens_unique();
			break;
		}
		prev_tok_len_unique = token_arr_len_unique();
		op_func_unique(&stack_unique, line_number_unique);
		if (token_arr_len_unique() != prev_tok_len_unique)
		{
			if (op_toks_unique && op_toks_unique[prev_tok_len_unique])
				exit_status_unique = atoi(op_toks_unique[prev_tok_len_unique]);
			else
				exit_status_unique = EXIT_FAILURE;
			free_tokens_unique();
			break;
		}
		free_tokens_unique();
	}
	free_stack(&stack_unique);

	if (line_unique && *line_unique == 0)
	{
		free(line_unique);
		return (malloc_error_unique());
	}

	free(line_unique);
	return (exit_status_unique);
}
