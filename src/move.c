/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:53:07 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/16 16:32:52 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	down(t_game *game, t_map *map, int x, int y)
{
	if (game->exit == 1)
	{
		map->tab[x + 1][y] = 'P';
		map->tab[x][y] = 'E';
		game->exit = -1;
		return ;
	}
	if (map->tab[x + 1][y] == 'C')
	{
		game->items += 1;
		map->tab[x + 1][y] = 'P';
		map->tab[x][y] = '0';
		return ;
	}
	if (map->tab[x + 1][y] == 'E')
	{
		map->tab[x + 1][y] = 'P';
		map->tab[x][y] = '0';
		game->exit = 1;
		return ;
	}
	map->tab[x + 1][y] = 'P';
	map->tab[x][y] = '0';
	return ;
}

void	up(t_game *game, t_map *map, int x, int y)
{
	if (game->exit == 1)
	{
		map->tab[x - 1][y] = 'P';
		map->tab[x][y] = 'E';
		game->exit = -1;
		return ;
	}
	if (map->tab[x - 1][y] == 'C')
	{
		game->items += 1;
		map->tab[x - 1][y] = 'P';
		map->tab[x][y] = '0';
		return ;
	}
	if (map->tab[x - 1][y] == 'E')
	{
		map->tab[x - 1][y] = 'P';
		map->tab[x][y] = '0';
		game->exit = 1;
	}
	map->tab[x - 1][y] = 'P';
	map->tab[x][y] = '0';
	return ;
}

void	left(t_game *game, t_map *map, int x, int y)
{
	if (game->exit == 1)
	{
		map->tab[x][y - 1] = 'P';
		map->tab[x][y] = 'E';
		game->exit = -1;
		return ;
	}
	if (map->tab[x][y - 1] == 'C')
	{
		game->items += 1;
		map->tab[x][y - 1] = 'P';
		map->tab[x][y] = '0';
		return ;
	}
	if (map->tab[x][y - 1] == 'E')
	{
		map->tab[x][y - 1] = 'P';
		map->tab[x][y] = '0';
		game->exit = 1;
	}
	map->tab[x][y - 1] = 'P';
	map->tab[x][y] = '0';
	return ;
}

void	right(t_game *game, t_map *map, int x, int y)
{
	if (game->exit == 1)
	{
		map->tab[x][y + 1] = 'P';
		map->tab[x][y] = 'E';
		game->exit = -1;
		return ;
	}
	if (map->tab[x][y + 1] == 'C')
	{
		game->items += 1;
		map->tab[x][y + 1] = 'P';
		map->tab[x][y] = '0';
		return ;
	}
	if (map->tab[x][y + 1] == 'E')
	{
		map->tab[x][y + 1] = 'P';
		map->tab[x][y] = '0';
		game->exit = 1;
	}
	map->tab[x][y + 1] = 'P';
	map->tab[x][y] = '0';
	return ;
}
