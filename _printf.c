#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
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
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				count += write(1, &va_arg(args, int), 1);
				break;
			case 's':
			{
				char *str = va_arg(args, char *);

				for (int j = 0; str[j] != '\0'; j++)
					count += write(1, &str[j], 1);
				break;
			}
			case '%':
				count += write(1, &format[i], 1);
				break;
			case 'd':
			case 'i':
				count += print_number(va_arg(args, int));
				break;
			default:
				break;
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
