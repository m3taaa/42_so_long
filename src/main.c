/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:12:47 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/21 14:50:14 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->items = 0;
	game->exit = -1;
	game->move = 1;
	game->check_items = 0;
	game->check_exit = 0;
	init_map(&game->map);
}

int	main(int ac, char **av)
{
	int		return_path;
	t_game	game;

	if (ac < 2 || ac > 2)
		return (1);
	init_game(&game);
	game.map = check_file(av[1]);
	check_map(&game.map);
	return_path = check_path(game);
	if (return_path == 1)
		error("map impossible\n", &game.map);
	start_game(&game);
	return (0);
}
