/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:53:13 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/16 16:36:25 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	print_wall(t_game *game, t_image img, int x, int y)
{
	int		img_height;
	int		img_width;

	img.img = mlx_xpm_file_to_image \
	(game->mlx, "images/wall.xpm", &img_width, &img_height);
	if (img.img == NULL)
		error("Error loading image\n", &game->map);
	mlx_put_image_to_window(game->mlx, game->window, img.img, x, y);
}

void	print_perso(t_game *game, t_image img, int x, int y)
{
	int		img_height;
	int		img_width;

	img.img = mlx_xpm_file_to_image \
	(game->mlx, "images/perso.xpm", &img_width, &img_height);
	if (img.img == NULL)
		error("Error loading image\n", &game->map);
	mlx_put_image_to_window(game->mlx, game->window, img.img, x, y);
}

void	print_item(t_game *game, t_image img, int x, int y)
{
	int		img_height;
	int		img_width;

	img.img = mlx_xpm_file_to_image \
	(game->mlx, "images/item.xpm", &img_width, &img_height);
	if (img.img == NULL)
		error("Error loading image\n", &game->map);
	mlx_put_image_to_window(game->mlx, game->window, img.img, x, y);
}

void	print_exit(t_game *game, t_image img, int x, int y)
{
	int	img_height;
	int	img_width;

	img.img = mlx_xpm_file_to_image \
	(game->mlx, "images/exit.xpm", &img_width, &img_height);
	if (img.img == NULL)
		error("Error loading image\n", &game->map);
	mlx_put_image_to_window(game->mlx, game->window, img.img, x, y);
}
