/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:57:42 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/18 13:14:50 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	get_data_print_image(t_image *image, t_game *game)
{
	image->img = mlx_new_image \
	(game->mlx, (game->map.size_x * 64), (game->map.size_y * 64));
	if (image->img == NULL)
		error("Error mlx", &game->map);
	image->addr = mlx_get_data_addr \
	(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	if (image->addr == NULL)
		error("Error mlx", &game->map);
}

static void	free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	error(char *msg, t_map *map)
{
	if (map && map->tab != NULL)
		free_tab(map->tab);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	exit_game(t_map *map)
{
	free_tab(map->tab);
	exit (0);
}

void	init_map(t_map *map)
{
	map->perso = 0;
	map->items = 0;
	map->exit_game = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->tab = NULL;
}
