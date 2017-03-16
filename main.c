#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int 	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
		printf("gnl = %d *____* line = %s\n", gnl, line);
	printf("gnl = %d *____* line = %s\n", gnl, line);
	return (0);
}
