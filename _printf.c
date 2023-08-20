#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _putchar - writes the character c
 * @c: The character to print
 * * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_unknown - prints an unknown
 * @c: the character
 * Return: number of characters
 */
int print_unknown(char c)
{
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * print_number - prints an integer
 * @n: integer to be printed
 * Return: number of characters
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;
	if (num / 10 != 0)
		count += print_number(num / 10);
	_putchar((num % 10) + '0');
	count++;
	return (count);
}

/**
 * print_string - prints a string
 * @str: string to be printed
 * Return: number of characters
 */
int print_string(char *str)
{
	int count = 0, j;

	for (j = 0; str[j] != '\0'; j++)
		count += write(1, &str[j], 1);
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				count += _putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i] == '%')
				count += write(1, &format[i], 1);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
			else if (format[i] == 'u')
				count += print_unsigned_int(va_arg(args, unsigned int));
			else if (format[i] == 'o')
				count += print_octal(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				count += print_hex(va_arg(args, unsigned int), 0);
			else if (format[i] == 'X')
				count += print_hex(va_arg(args, unsigned int), 1);
			else if (format[i] == 'p')
				count += print_address(va_arg(args, void *));
			else
				count += print_unknown(format[i]);
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
