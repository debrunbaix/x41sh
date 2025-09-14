#include	"../../include/libc/x41_libc.h"

/**
 * Function to display strings withous '\n'.
 */
int		x41_puts_util(const char *s)
{
		int	i;
		ssize_t	ret;
		
		ret = x41_write(STDOUT, s, x41_strlen(s));
		return	ret;
}

int		x41_printf(const char *format, ...)
{
		va_list	va;
		va_start(va, format);

		while (*format)
		{
				if (*format != '%')
				{
						x41_putchar(*format);
						++format;
						continue;
				}
				++format;
				switch (*format)
				{
						case 'd':
								x41_putnbr(va_arg(va, int));
								++format;
								break;
						case 's':
								x41_puts_util(va_arg(va, const char *));
								++format;
								break;
						case 'c':
								x41_putchar(va_arg(va, int));
								++format;
								break;
						default:
								x41_puts_util("%");
								continue;
				}
		}
		va_end(va);
		return	SUCCESS;
}
