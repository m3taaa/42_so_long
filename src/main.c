#include "../header/so_long.h"

int main(int ac, char **av)
{
	int fd;
	int return_check_content;
	if (ac != 2)
	{
		if (ac < 2)
			ft_printf("Veuillez ajouter en argument une map\n");
		else
			ft_printf("error\n");
		return (0);
	}
	ft_printf("ok\n");
	fd = check_file(av[1]);
	if (fd == -1)
		return (0);
	return_check_content = check_content_file(fd);
	if (return_check_content == 1)
	{
		ft_printf("Map incorect\n");
		return (0);
	}
	return (0);
}
