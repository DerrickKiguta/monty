#include <stdlib.h>

char *convert_to_string(int number);
unsigned int absolute_value(int value);
int calculate_string_length(unsigned int number, unsigned int base);
void fill_buffer(unsigned int number, unsigned int base, char *buffer, int buffer_size);

/**
 * convert_to_string - Converts an integer to a string.
 * @number: Number to convert to a string.
 * Return: Pointer to the newly created string. NULL if malloc fails.
 */
char *convert_to_string(int number)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *result;

	temp = absolute_value(number);
	length = calculate_string_length(temp, 10);

	if (number < 0 || num_l < 0)
		length++; /* Include negative sign */
	result = malloc(length + 1); /* Create new string */
	if (!result)
		return NULL;

	fill_buffer(temp, 10, result, length);
	if (number < 0 || num_l < 0)
		result[0] = '-';

	return result;
}

/**
 * absolute_value - Calculates the absolute value of an integer.
 * @value: Integer to calculate the absolute value of.
 * Return: Unsigned integer representing the absolute value of value.
 */
unsigned int absolute_value(int value)
{
	if (value < 0)
		return (unsigned int)(-value);
	return (unsigned int)value;
}

/**
 * calculate_string_length - Calculates the length of a buffer needed for an unsigned integer.
 * @number: Number to calculate the length for.
 * @base: Base of the number representation used by the buffer.
 * Return: Integer representing the length of the buffer needed (excluding null byte).
 */
int calculate_string_length(unsigned int number, unsigned int base)
{
	int length = 1; /* All numbers contain at least one digit */

	while (number > base - 1)
	{
		length++;
		number /= base;
	}
	return length;
}

/**
 * fill_buffer - Fills a buffer with correct numbers up to base 36.
 * @number: Number to convert to string given the base.
 * @base: Base of the number used in the conversion (works up to base 36).
 * @buffer: Buffer to fill with the result of the conversion.
 * @buffer_size: Size of the buffer in bytes.
 * Return: Always void.
 */
void fill_buffer(unsigned int number, unsigned int base, char *buffer, int buffer_size)
{
	int remainder, i = buffer_size - 1;

	buffer[buffer_size] = '\0';
	while (i >= 0)
	{
		remainder = number % base;
		if (remainder > 9) /* Return lowercase ASCII value representation */
			buffer[i] = remainder + 87; /* 10 will be 'a', 11 = 'b', ... */
		else
			buffer[i] = remainder + '0';
		number /= base;
		i--;
	}
}
