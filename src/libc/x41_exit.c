#include	"../../include/libc/x41_libc.h"

void	x41_exit(int status)
{
		int		ret;

		__asm__ volatile (
				"syscall"
				: "=a"(ret)
				: "a"(60), "D"(status)
				: "memory"
		);
}
