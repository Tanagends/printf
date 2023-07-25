#include "main.h"
/**
 * _printf - prints formatted output.
 * @format: character string.
 * Return: character output count.
 */
int _printf(const char *format, ...)
{
	size_t i = 0, count = 0, t, m, lenstr;
	va_list arg1;
	char copy[BUFFSIZE];
	const char *str;

	va_start(arg1, format);
	if (format == NULL)
		exit(EXIT_FAILURE);
	while (format[i] && count < BUFFSIZE)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				str = va_arg(arg1, char *);
				lenstr = 0;
				while (str[lenstr++] != '\0')
					count++;
				m = 0;
				for (t = count; t < count + lenstr; t++)
					copy[t] = str[m++];
			}
			else if (format[i] == 'c')
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
	va_end(arg1);
	write(1, copy, count);
	return (count);
}
