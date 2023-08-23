#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "main.h"

/**
 * print_args - Prints arguments
 * @format: The format specifier
 * @args: The argument
 * @count: Pointer to the count of printed characters
 *
 * Return: The number of characters printed
 */
int print_args(char format, va_list args, int *count)
{
	int printed = 0;

	switch (format)
	{
		case 'c':
			_putchar(va_arg(args, int));
			printed++;
			break;
		case 's':
			print_string(va_arg(args, char *), count);
			printed++;
			break;
		case 'i':
		case 'd':
			print_integer(va_arg(args, int), count);
			printed++;
			break;
		default:
			return (-1);
	}
	return (printed);
}
