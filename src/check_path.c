/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:57 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/16 16:29:59 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	find_user(t_game *game, int *x, int *y)
{
	*x = 0;
	while (game->map.tab[*x])
	{
		*y = 0;
		while (game->map.tab[*x][*y])
		{
			if (game->map.tab[*x][*y] == 'P')
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

void	try_map(int x, int y, t_game *game)
{
	if (game->map.tab[x][y] == '1' || game->map.tab[x][y] == 'X' \
			|| game->map.tab[x][y] == 'c')
		return ;
	else if (game->map.tab[x][y] == '0')
		game->map.tab[x][y] = 'X';
	else if (game->map.tab[x][y] == 'C')
	{
		game->check_items++;
		game->map.tab[x][y] = 'c';
	}
	else if (game->map.tab[x][y] == 'E' && game->check_exit == 0)
		game->check_exit = 1;
	try_map(x + 1, y, game);
	try_map(x - 1, y, game);
	try_map(x, y + 1, game);
	try_map(x, y - 1, game);
}

int	check_path(t_game game)
{
	int		x;
	int		y;
	t_game	*game_temp;

	game_temp = &game;
	find_user(game_temp, &x, &y);
	try_map(x, y, game_temp);
	if (game_temp->check_items != game.map.items || game_temp->check_exit == 0)
		return (1);
	x = 0;
	while (game_temp->map.tab[x])
	{
		y = 0;
		while (game_temp->map.tab[x][y])
		{
			if (game_temp->map.tab[x][y] == 'c')
				game_temp->map.tab[x][y] = 'C';
			y++;
		}
		x++;
	}
	return (0);
}
