/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:20:23 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/19 20:00:06 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft_and_more.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define W 13
# define A 0
# define S 2
# define D 1
# define ESC 53

typedef struct s_map
{
	int		items;
	int		exit_game;
	int		perso;
	int		size_x;
	int		size_y;
	char	**tab;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_image;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*window;
	int		items;
	int		exit;
	int		move;
	int		check_items;
	int		check_exit;
}	t_game;

int			check_map(t_map *map);
int			check_path(t_game game);
int			exit_game(t_map *map);
void		error(char *msg, t_map *map);
void		get_data_print_image(t_image *image, t_game *game);
void		start_game(t_game *game);
void		print_wall(t_game *game, t_image img, int x, int y);
void		print_item(t_game *game, t_image img, int x, int y);
void		print_exit(t_game *game, t_image img, int x, int y);
void		print_perso(t_game *game, t_image img, int x, int y);
void		init_map(t_map *map);
void		down(t_game *game, t_map *map, int x, int y);
void		up(t_game *game, t_map *map, int x, int y);
void		left(t_game *game, t_map *map, int x, int y);
void		right(t_game *game, t_map *map, int x, int y);
t_map		check_file(char *file);
#endif
