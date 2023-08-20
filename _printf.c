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
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i, j;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				int c = va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if(format[i] == 's')
			{
				char *str = va_arg(args, char *);

				for (j = 0; str[j] != '\0'; j++)
					count += write(1, &str[j], 1);
			}
			else if (format[i] == '%')
				count += write(1, &format[i], 1);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
