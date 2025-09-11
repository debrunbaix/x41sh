#include "../include/libc/x41_libc.h"

int		main(int argc, char **argv, char **envp)
{
		x41_strlen("test\0");
		return SUCCESS;
}
