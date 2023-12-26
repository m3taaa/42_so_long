/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:20:56 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/19 17:00:32 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	get_data(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->tab[x])
	{
		y = 0;
		while (map->tab[x][y])
		{
			if (map->tab[x][y] != '0' && map->tab[x][y] != '1' \
			&& map->tab[x][y] != 'P' && map->tab[x][y] != 'C' \
			&& map->tab[x][y] != 'E')
				error("map invalid\n", map);
			if (map->tab[x][y] == 'C')
				map->items += 1;
			if (map->tab[x][y] == 'E')
				map->exit_game += 1;
			if (map->tab[x][y] == 'P')
				map->perso += 1;
			y++;
		}
		x++;
	}
}

static void	check_data(t_map *map)
{
	if (map->items < 1 || map->exit_game != 1 || map->perso != 1)
		error("too few or too many elements\n", map);
}

static void	check_len(t_map *map)
{
	int		x;
	int		len;
	int		len_tmp;

	x = 0;
	len = ft_strlen(map->tab[0]);
	while (map->tab[x])
	{
		len_tmp = ft_strlen(map->tab[x]);
		if (len_tmp != len)
			error("your map is invalid\n", map);
		x++;
	}
	if (x > 500)
		error("too large map\n", map);
}

static void	check_border(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->tab[x])
	{
		y = 0;
		if (x == 0 || x == (map->size_y) - 1)
		{
			while (map->tab[x][y])
			{
				if (map->tab[x][y] != '1')
					error("border error\n", map);
				y++;
			}
		}
		else
		{
			if (map->tab[x][0] != '1' \
				|| map->tab[x][ft_strlen(map->tab[x]) - 1] != '1')
				error("border error\n", map);
		}
		x++;
	}
}

int	check_map(t_map *map)
{
	get_data(map);
	check_data(map);
	check_len(map);
	check_border(map);
	return (0);
}
