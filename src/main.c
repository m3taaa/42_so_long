#include "../header/so_long.h"

void	simple_window()
{
	void	*ptr_mlx;
	void	*ptr_window;

	ptr_mlx = mlx_init();
	ptr_window = mlx_new_window(ptr_mlx, 500, 500, "test");
	ft_printf("%p\n",ptr_window);
	mlx_loop(ptr_mlx);
	return ;
}

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
	fd = check_file(av[1]);
	if (fd == -1)
		return (0);
	return_check_content = check_content_file(fd);
	if (return_check_content == 1)
	{
		ft_printf("Map incorect\n");
		return (0);
	}
	simple_window();
	return (0);
}
