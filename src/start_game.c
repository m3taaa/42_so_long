/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:40:53 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/19 20:03:14 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
 * tab[0] = x
 * tab[1] = y
 */

void	print_image(t_game *game)
{
	t_image		image;
	int			tab_int[2];

	get_data_print_image(&image, game);
	tab_int[0] = 0;
	while (game->map.tab[tab_int[0]])
	{
		tab_int[1] = 0;
		while (game->map.tab[tab_int[0]][tab_int[1]])
		{
			if (game->map.tab[tab_int[0]][tab_int[1]] == '1')
				print_wall(game, image, (tab_int[1] * 64), (tab_int[0] * 64));
			else if (game->map.tab[tab_int[0]][tab_int[1]] == 'P')
				print_perso(game, image, (tab_int[1] * 64), (tab_int[0] * 64));
			else if (game->map.tab[tab_int[0]][tab_int[1]] == 'C')
				print_item(game, image, (tab_int[1] * 64), (tab_int[0] * 64));
			else if (game->map.tab[tab_int[0]][tab_int[1]] == 'E')
				print_exit(game, image, (tab_int[1] * 64), (tab_int[0] * 64));
			tab_int[1]++;
		}
		tab_int[0]++;
	}
}

void	moving_user(t_game *game, t_map *map, int move, int x)
{
	int	y;

	y = 0;
	while (map->tab[x])
	{
		y = 0;
		while (map->tab[x][y])
		{
			if (map->tab[x][y] == 'P')
			{
				if (move == D && map->tab[x + 1][y] != '1')
					down(game, map, x, y);
				else if (move == W && map->tab[x - 1][y] != '1')
					up(game, map, x, y);
				else if (move == A && map->tab[x][y - 1] != '1')
					left(game, map, x, y);
				else if (move == S && map->tab[x][y + 1] != '1')
					right(game, map, x, y);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	remap(t_game *game, int move)
{
	int	x;

	x = 0;
	ft_printf("move : %d\n", game->move);
	moving_user(game, &game->map, move, x);
	if (game->items == game->map.items && game->exit != -1)
		exit_game(&game->map);
	game->move++;
	mlx_clear_window(game->mlx, game->window);
	print_image(game);
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		exit_game(&game->map);
	if (key == W)
		remap(game, key);
	if (key == A)
		remap(game, key);
	if (key == S)
		remap(game, key);
	if (key == D)
		remap(game, key);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("Error mlx\n", &game->map);
	if (game->map.size_y > 50 || game->map.size_x > 50)
		error("map is too big\n", &game->map);
	game->window = mlx_new_window \
	(game->mlx, (game->map.size_x * 64), (game->map.size_y * 64), "so_long");
	if (!game->window)
		error("Error mlx\n", &game->map);
	print_image(game);
	mlx_key_hook(game->window, press_key, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}
