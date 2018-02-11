#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(void)
{
	int fd = open("1.txt", O_RDONLY);
	int rv = 1;
	char *buf;

	while (rv && rv != -1)
	{
		rv = get_next_line(fd, &buf);
		printf("%s\n", buf);
		free(buf);
	}
	return (0);
}
