#include	"../../include/libc/x41_libc.h"

int		x41_strncmp(const char *s1, const char *s2, size_t n)
{
		size_t	i = 1;

		while (i < n && (*s1 == *s2))
		{
				s1++;
				s2++;
				i++;
		}
		return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
