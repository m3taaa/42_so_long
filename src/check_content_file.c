#include "../header/so_long.h"

int		check_line(char *line)
{
	int x;

	x = 0;
	while (line[x] != '\n')
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != 'C' && line[x] != 'E' && line[x] != 'P')
			return (1);
		x++;
	}
	return (0);
}

int		check_content_file(int fd)
{
	char *line;
	int 	return_line;

	while (line = get_next_line(fd))
	{
		return_line = check_line(line);
		if (return_line == 1)
			return (1);
		free(line);
	}
	return (0);
}
