#include "monty.h"

/**
 * set_op_tok_error_unique - Sets last element of op_toks_unique to be an error code.
 * @error_code: Integer to store as a string in op_toks_unique.
 */
void set_op_tok_error_unique(int error_code)
{
	int toks_len_unique = 0, i = 0;
	char *exit_str_unique = NULL;
	char **new_toks_unique = NULL;

	toks_len_unique = token_arr_len_unique();
	new_toks_unique = malloc(sizeof(char *) * (toks_len_unique + 2));
	if (!op_toks_unique)
	{
		malloc_error_unique();
		return;
	}
	while (i < toks_len_unique)
	{
		new_toks_unique[i] = op_toks_unique[i];
		i++;
	}
	exit_str_unique = get_int_unique(error_code);
	if (!exit_str_unique)
	{
		free(new_toks_unique);
		malloc_error_unique();
		return;
	}
	new_toks_unique[i++] = exit_str_unique;
	new_toks_unique[i] = NULL;
	free(op_toks_unique);
	op_toks_unique = new_toks_unique;
}
