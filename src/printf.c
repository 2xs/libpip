#include <stdarg.h>

#include "pip/stdio.h"

static char *convert(unsigned int integer, unsigned int base);
static char *uppercase(char *ptr);

/*!
 * \fn extern void printf(const char *format, ...)
 * \brief Print a formatted string on the serial link
 * \param format The formatted string to print
 */
extern void printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);

	for (unsigned int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i+1])
			{
				case '%':
				{
					putchar('%');
					break;
				}
				case 'b':
				{
					unsigned int arg = va_arg(ap, unsigned int);
					puts(convert(arg, 2));
					break;
				}
				case 'o':
				{
					unsigned int arg = va_arg(ap, unsigned int);
					puts(convert(arg, 8));
					break;
				}
				case 'd':
				case 'i':
				{
					int arg = va_arg(ap, int);
					if (arg < 0)
					{
						putchar('-');
						arg = -arg;
					}
					puts(convert(arg, 10));
					break;
				}
				case 'x':
				{
					unsigned int arg = va_arg(ap, unsigned int);
					puts(convert(arg, 16));
					break;
				}
				case 'X':
				{
					unsigned int arg = va_arg(ap, unsigned int);
					puts(uppercase(convert(arg, 16)));
					break;
				}
				case 'c':
				{
					int arg = va_arg(ap, int);
					putchar(arg);
					break;
				}
				case 's':
				{
					char *arg = va_arg(ap, char *);
					puts(arg);
					break;
				}
			}

			i++;
		}
		else
		{
			putchar(format[i]);
		}
	}

	va_end(ap);
}

/*!
 * \fn static char *convert(unsigned int integer, unsigned int base)
 * \brief Converts an integer into a string in the desired base
 * \param integer The integer to convert into a string
 * \param base The base in which to convert the integer
 */
static char *convert(unsigned int integer, unsigned int base)
{
	char const charset[] = "0123456789abcdef";
	static char buf[33];
	char *ptr;

	ptr  = &buf[32];
	*ptr = '\0';

	if (base > 1 && base < 17)
	{
		do
		{
			*--ptr = charset[integer%base];
			integer /= base;
		} while (integer);
	}

	return ptr;
}

/*!
 * \fn static char *uppercase(char *ptr)
 * \brief Capitalize a string
 * \param ptr The string to capitalize
 */
static char *uppercase(char *ptr)
{
	for (unsigned int i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] >= 'a' && ptr[i] <= 'f')
		{
			ptr[i] -= 32;
		}
	}

	return ptr;
}
