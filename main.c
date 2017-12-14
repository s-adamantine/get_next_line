#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int	fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	while (1)
		(void)line;
}
