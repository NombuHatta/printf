#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - Prints a single characters
 * @c: The character
 * @count: Pointer to the count of printed characters
 */
void print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - Prints a string
 * @s: The string to print
 * @count: Pointer to the count of printed characters
 */
void print_string(char *s, int *count)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	write(1, s, len);
	(*count) += len;
}

/**
 * print_integer - Prints an integer
 * @num: The integer to print
 * @count: Pointer to the count of printed characters
 */
void print_integer(int num, int *count)
{
	int num_copy = num;
	int i, digits = 0;
	char *num_str;

	if (num_copy == 0)
		digits = 1;
	else
	{
		while (num_copy != 0)
		{
			num_copy /= 10;
			digits++;
		}
	}

	num_str = (char *)malloc(digits + 1);
	if (num_str == NULL)
	{
		return;
	}
	num_str[digits] = '\0';

	for (i = digits - 1; i >= 0; i--)
	{
		num_str[i] = '0' + (num % 10);
		num /= 10;
	}

	write(1, num_str, digits);
	(*count) += digits;
	free(num_str);
}
