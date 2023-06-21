#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks_unique = NULL;

/**
 * main_unique - the entry point for Monty Interp
 *
 * @argc_unique: the count of arguments passed to the program
 * @argv_unique: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main_unique(int argc_unique, char **argv_unique)
{
	FILE *script_fd_unique = NULL;
	int exit_code_unique = EXIT_SUCCESS;

	if (argc_unique != 2)
		return (usage_error_unique());
	script_fd_unique = fopen(argv_unique[1], "r");
	if (script_fd_unique == NULL)
		return (f_open_error_unique(argv_unique[1]));
	exit_code_unique = run_monty_unique(script_fd_unique);
	fclose(script_fd_unique);
	return (exit_code_unique);
}
