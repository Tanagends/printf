#include "main.h"
/**
 * _printf - prints formatted output.
 * @format: character string.
 * Return: character output count.
 */
int _printf(const char *format, ...)
{
	size_t i = 0, count = 0, t, m, lenf;
	va_list arg1;
	char copy[BUFFSIZE];
	const char *str;

	va_start(arg1, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				str = va_arg(arg1, char *);
				lenf = 0;
				while (str[lenf++])
					count++;
				m = 0;
				for (t = count; t < count + lenf; t++)
					copy[t] = str[m++];
			}
			else if (format [i] == 'c')
				copy[count++] = (char)va_arg(arg1, int);
			else
			{
				copy[count++] = format[--i];
				copy[count++] = format[++i];
			}
		}
		else
			copy[count++] = format[i];
		i++;
	}
	write(1, copy, count);
	return (count);
}
