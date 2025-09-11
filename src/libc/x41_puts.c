#include	"../../include/libc/x41_libc.h"

int		x41_puts(const char *s)
{
		int	i;
		ssize_t	ret;
		
		ret = x41_write(1, s, sizeof(s));
		x41_putchar('\n');
		return	ret;
}
