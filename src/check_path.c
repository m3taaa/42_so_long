/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:57 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/21 14:49:01 by mmeerber         ###   ########.fr       */
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
			|| game->map.tab[x][y] == 'c' || game->map.tab[x][y] == 'e')
		return ;
	else if (game->map.tab[x][y] == '0')
		game->map.tab[x][y] = 'X';
	else if (game->map.tab[x][y] == 'C')
	{
		game->check_items++;
		game->map.tab[x][y] = 'c';
	}
	else if (game->map.tab[x][y] == 'E' && game->check_exit == 0)
	{
		game->check_exit = 1;
		game->map.tab[x][y] = 'e';
	}
	try_map(x + 1, y, game);
	try_map(x - 1, y, game);
	try_map(x, y + 1, game);
	try_map(x, y - 1, game);
}

// tab_int[0] = x
// tab_int[1] = y
int	check_path(t_game game)
{
	int		tab_int[2];
	t_game	*game_temp;

	game_temp = &game;
	find_user(game_temp, &tab_int[0], &tab_int[1]);
	try_map(tab_int[0], tab_int[1], game_temp);
	if (game_temp->check_items != game.map.items || game_temp->check_exit == 0)
		return (1);
	tab_int[0] = 0;
	while (game_temp->map.tab[tab_int[0]])
	{
		tab_int[1] = 0;
		while (game_temp->map.tab[tab_int[0]][tab_int[1]])
		{
			if (game_temp->map.tab[tab_int[0]][tab_int[1]] == 'c')
				game_temp->map.tab[tab_int[0]][tab_int[1]] = 'C';
			if (game_temp->map.tab[tab_int[0]][tab_int[1]] == 'e')
				game_temp->map.tab[tab_int[0]][tab_int[1]] = 'E';
			tab_int[1]++;
		}
		tab_int[0]++;
	}
	return (0);
}
