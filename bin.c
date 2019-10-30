#include "holberton.h"
#include <stdarg.h>

/**
* bin - convert to binary
* @argumentos: number to convert
* Return: len of binary
*/

int bin(va_list argumentos)
{
	int st[1000000];
	int mod, n, j, i = 0;

	n = va_arg(argumentos, int);

	while (n != 0)
	{
		mod = n % 2;
		n = n / 2;
		st[i] = mod;
		i++;
	}

	for (j = (i - 1) ; j >= 0 ; j--)
	{
		_putchar(st[j] + '0');
	}

	return (i - 1);
}