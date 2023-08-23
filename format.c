#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


/**
 * print_string - Prints a string
 * @s: The string to print
 * @count: Pointer to the count of printed characters
 */
void print_string(char *s, int *count)
{
	int len = strlen(s);

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

	if (num_copy < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num_copy = -num_copy;
	}
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
