#include	"../../include/libc/x41_libc.h"

ssize_t	x41_read(int fd, void *buf, size_t n)
{
		long	ret;

		__asm__ volatile (
				"syscall"
				: "=a"(ret)
				: "a"(0), "D"(fd), "S"(buf), "d"(n)
				: "memory"
		);
		return	ret;
}
