#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

/**
* _printf - function that produces output according to a format.
* @format : type of format for print
* Return: length of string
*/

int _printf(const char *format, ...)
{
	va_list argumentos;
	int i = 0, j = 0, c = 0, d = 0, a = 0;

	op_t ops[] = {{"c", printchar}, {"s", printstring},
	{"i", printint}, {"d", printd}, {NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(argumentos, format);
	if (argumentos == NULL)
		return (-1);

	while (format[i]) /* recorrer format */
	{
		if (format[i] == 37 || a == 1)
		{
			if (format[i + 1] != 37) /*Si el caracter siguiente no es %*/
			{
				j = 0;
				a = 1;
				while (ops[j].op != NULL)
				{
					if (format[i + 1] == *(ops[j].op))
					{
						c = (ops[j].f)(argumentos);
						i = i + 2;
						a = 0;
						break;
					}
					j++;
				}
			}
			if (format[i + 1] == 37) /*si el caracter siguiente es % avanzo 1 pos*/
			{
				a = 0;
				i++;
			}
		}
		if (a == 0)
		_putchar(format[i]);
		i++;
		d++;
	}
	va_end(argumentos);
	return (d + c);
}
