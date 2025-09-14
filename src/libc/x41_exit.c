#include	"../../include/libc/x41_libc.h"

/**
 * Function to exit program with status code as param.
 *
 * status: exit code
 */
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
