#ifndef	X41_LIBC_H
#define	X41_LIBC_H

#include	"x41_types.h"

#define	STDIN	0
#define	STDOUT	1
#define STDERR	2
#define	ERROR	-1
#define	SUCCESS	0

ssize_t	x41_write(int fd, const void *buf, size_t n);
int		x41_putchar(int c);
int		x41_puts(const char *s);
size_t	x41_strlen(const char *s);
int		x41_putnbr(int num);
int		x41_strcmp(const char *s1, const char *s2);
int		x41_strncmp(const char *s1, const char *s2, size_t n);
ssize_t	x41_read(int fd, void *buf, size_t n);
void	x41_exit(int status);

#endif
