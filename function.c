#include "main.h"
#include <stdarg.h>
#include <stdint.h>
/**
 * print_unsigned_int - prints an unsigned integer
 * @n: unsigned integer to be printed
 * Return: number of characters
 */
int print_unsigned_int(unsigned int n)
{
	int count = 0;

	if (n / 10 != 0)
		count += print_unsigned_int(n / 10);
	_putchar((n % 10) + '0');
	count++;
	return (count);
}

/**
 * print_octal - prints an unsigned integer in octal
 * @n: unsigned integer to be printed
 * Return: number of characters
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8 != 0)
		count += print_octal(n / 8);
	_putchar((n % 8) + '0');
	count++;
	return (count);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal
 * @n: unsigned integer to be printed
 * @uppercase: flag to indicate if the output should be in uppercase
 * Return: number of characters
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char c;

	if (n / 16 != 0)
		count += print_hex(n / 16, uppercase);
	c = (n % 16) < 10 ? (n % 16) + '0' : (n % 16) - 10 + (uppercase ? 'A' : 'a');
	_putchar(c);
	count++;
	return (count);
}

/**
 * print_address - prints an address in hexadecimal
 * @p: pointer to be printed
 * Return: number of characters
 */
int print_address(void *p)
{
	int count = 0;
	unsigned long n = (unsigned long)p;

	_putchar('0');
	_putchar('x');
	count += 2;
	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
		count += print_hex_address(n);
	return (count);
}

/**
 * print_hex_address - recursive function to print an address in hexadecimal
 * @n: address to be printed
 * Return: number of characters
 */
int print_hex_address(unsigned long n)
{
	int count = 0;
	char c;

	if (n / 16 != 0)
		count += print_hex_address(n / 16);
	c = (n % 16) < 10 ? (n % 16) + '0' : (n % 16) - 10 + 'a';
	_putchar(c);
	count++;
	return (count);
}
