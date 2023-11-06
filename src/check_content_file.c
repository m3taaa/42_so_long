#include "../header/so_long.h"

static int	check_line(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] != '0' || str[x] != '1' || str[x] != 'C' || str[x] != 'E' || str[x] != 'P')
			return (1);
		x++;	
	}
	return (0);
}
int		check_content_file(int fd)
{
	char *line;
	int		i;
	int 	return_line;

	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		return_line = check_line(line);
		if (return_line == 1)
			return (1);
		ft_printf("%d. %s\n",i, line);
		if (line == NULL)
			break;
		free(line);
		i++;
	}
	return (0);
}
