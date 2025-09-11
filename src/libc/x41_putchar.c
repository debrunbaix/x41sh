#include	"../../include/libc/x41_libc.h"

int		x41_putchar(int c)
{
		int		ret;
		char	ch;

		ch = (char)c;
		ret = (int)x41_write(1, &c, 1);
		return	ret;
}
