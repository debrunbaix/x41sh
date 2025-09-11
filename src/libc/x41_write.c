#include	"../../include/libc/x41_libc.h"

ssize_t	x41_write(int fd, const void *buf, size_t n)
{
		long	ret;

		__asm__ volatile (
				"syscall"
				: "=a"(ret)
				: "a"(1), "D"(fd), "S"(buf), "d"(n)
				: "memory"
		);
		return	ret;
}
