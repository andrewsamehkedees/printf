#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_number(int n);
int _printf(const char *format, ...);
int print_unsigned_int(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_address(void *p);
int print_unknown(char c);
int print_string(char *str);
int print_hex_address(unsigned long n);

#endif /* MAIN_H */
