#include "monty.h"

int print_short_stack_error(unsigned int line_number, char *operation);
int print_division_error(unsigned int line_number);
int print_pop_error(unsigned int line_number);
int print_pchar_error(unsigned int line_number, char *error_message);

/**
 * print_pop_error - Prints an error message for popping an empty stack.
 * @line_number: Line number in the script where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_pop_error(unsigned int line_number)
{
	fprintf(stderr, "ERROR: Cannot pop from an empty stack (line %u)\n", line_number);
	return EXIT_FAILURE;
}

/**
 * print_pint_error - Prints an error message for pint on an empty stack.
 * @line_number: Line number in the script where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_pint_error(unsigned int line_number)
{
	fprintf(stderr, "ERROR: Cannot pint, stack is empty (line %u)\n", line_number);
	return EXIT_FAILURE;
}

/**
 * print_short_stack_error - Prints an error message for operations on a short stack.
 * @line_number: Line number in the script where the error occurred.
 * @operation: The operation where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_short_stack_error(unsigned int line_number, char *operation)
{
	fprintf(stderr, "ERROR: Cannot perform '%s' operation, stack is too short (line %u)\n", operation, line_number);
	return EXIT_FAILURE;
}

/**
 * print_division_error - Prints an error message for division by zero.
 * @line_number: Line number in the script where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int print_division_error(unsigned int line_number)
{
	fprintf(stderr, "ERROR: Division by zero is not allowed (line %u)\n", line_number);
	return EXIT_FAILURE;
}

/**
 * print_pchar_error - Prints an error message for invalid pchar operations.
 * @line_number: Line number in the script where the error occurred.
 * @error_message: The specific error message to display.
 * Return: (EXIT_FAILURE) always.
 */
int print_pchar_error(unsigned int line_number, char *error_message)
{
	fprintf(stderr, "ERROR: Cannot perform pchar, %s (line %u)\n", error_message, line_number);
	return EXIT_FAILURE;
}
