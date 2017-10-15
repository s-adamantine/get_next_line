#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

//argv is a pointer to the address of a pointer that will be used to save
//the line read by the file descriptor.

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		offset;
	char	buf[BUFF_SIZE];
	char	**line;

	line = ft_memalloc(1);
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, line) == 0)
	{
		printf("the next line is: %s\n", *line);
	}
	close(fd);
	return (0);
}
