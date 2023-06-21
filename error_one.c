#include "monty.h"

int print_usage_error(void);
int print_malloc_error(void);
int print_file_open_error(char *filename);
int print_unknown_opcode_error(char *opcode, unsigned int line_number);
int print_invalid_push_argument_error(unsigned int line_number);

/**
 * print_usage_error - Prints usage error messages.
 * Return: (EXIT_FAILURE) always.
 */
int print_usage_error(void)
{
	fprintf(stderr, "ERROR: Invalid usage. Correct format: monty <file>\n");
	return (EXIT_FAILURE);
}

/**
 * print_malloc_error - Prints memory allocation error messages.
 * Return: (EXIT_FAILURE) always.
 */
int print_malloc_error(void)
{
	fprintf(stderr, "ERROR: Memory allocation failed\n");
	return (EXIT_FAILURE);
}

/**
 * print_file_open_error - Prints file opening error messages with the filename.
 * @filename: Name of the file that failed to open.
 * Return: (EXIT_FAILURE) always.
 */
int print_file_open_error(char *filename)
{
	fprintf(stderr, "ERROR: Failed to open file: %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * print_unknown_opcode_error - Prints error messages for unknown instructions.
 * @opcode: Opcode where the error occurred.
 * @line_number: Line number in the Monty bytecode file where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_unknown_opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "ERROR: Unknown instruction '%s' at line %u\n",
		opcode, line_number);
	return (EXIT_FAILURE);
}

/**
 * print_invalid_push_argument_error - Prints error messages for invalid push arguments.
 * @line_number: Line number in the Monty bytecode file where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_invalid_push_argument_error(unsigned int line_number)
{
	fprintf(stderr, "ERROR: Invalid argument for 'push' at line %u\n", line_number);
	return (EXIT_FAILURE);
}
