#include	"../../include/libc/x41_libc.h"

size_t	x41_strlen(const char *s)
{
		size_t	len = 0;

		while (s[len] != '\0') len++;
		return	len;
}
