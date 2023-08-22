#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				count += print_args(*format, args, &count);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
