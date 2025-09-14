#include "../include/libc/x41_libc.h"

int		main(int argc, char **argv, char **envp)
{
		x41_printf("String: %s\nNumber: %d\nChar: %c\n", "Hello, World!", 41, 'X');
		return SUCCESS;
}
