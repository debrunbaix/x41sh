#include	"../../include/libc/x41_libc.h"

#define	INT_TO_CH	48;

/**
 * Function to display digits one by one recursivly with modulo.
 *
 * num : Number to display.
 */
int		recursion(int num)
{
		int	ret;
		char ch_n = (num % 10) + INT_TO_CH;

		if (num > 0)
		{
				recursion(num / 10);
				ret = x41_write(1, &ch_n, 1);
		}
		return ret;
}

/**
 * Function to display number.
 */
int		x41_putnbr(int num)
{
		int	ret;

		return	recursion(num);
}
