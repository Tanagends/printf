#include "main.h"
/**
 * _printf - prints formatted output.
 * @format: character string.
 * Return: character output count.
 */
int _printf(const char *format, ...)
{
	size_t i = 0, count = 0;
	va_list arg1;
	const char *str;

	va_start(arg1, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				str = va_arg(arg1, char *);
				count += write(1, str, _strlen(str));
			}
			else if (format[i] == 'c')
				count += write(1, (char *)va_arg(arg1, int *), 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(arg1);
	return (count);
}
/**
 * _strlen - computes string length.
 * @str: the string.
 * Return: string length.
 */
int _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
