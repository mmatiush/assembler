#include "libft.h"
#include "op.h"
#include <fcntl.h>
#include <stdio.h>

int		compiler(void)
{
	int fd;
	int n;
	char *str = "hello";

	if ((fd = open("write_test.cor", O_CREAT| O_APPEND | O_RDWR, 0777)) < 0)
	{
		ft_putstr("Open error\n");
		exit(0);
	}
	n = write(fd, str, 17);
	printf("%d\n", n);
	if (close(fd) < 0)
	{
		ft_putstr("Close error\n");
		exit(0);		
	}
	return (1);
}
