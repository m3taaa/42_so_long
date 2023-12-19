/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:12:58 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/19 19:43:42 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	check_extension(char *path_file)
{
	char	*end_file;
	int		x;

	end_file = ft_substr(path_file, (ft_strlen(path_file)-4), 4);
	x = ft_strncmp(end_file, ".ber", ft_strlen(end_file));
	if (x != 0)
	{
		free(end_file);
		return (1);
	}
	free(end_file);
	return (0);
}

static int	get_size_file(char *path_file)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		x++;
		free(line);
		line = get_next_line(fd);
	}
	if (x < 3 || x > 500)
		error("map invalid\n", NULL);
	return (x);
}

/*
for create_map :
		tab[0] = sizeline
		tab[1] = x
		tab[2] = y
*/

static void	create_map(int fd, t_map *map, char *path_file)
{
	int		tab_int[3];
	char	*line;

	map->size_y = get_size_file(path_file);
	map->tab = malloc(sizeof(char *) * (map->size_y) + 1);
	if (!map->tab)
		error("error malloc\n", map);
	tab_int[1] = 0;
	while (tab_int[1] < map->size_y)
	{
		line = get_next_line(fd);
		tab_int[2] = 0;
		tab_int[0] = ft_strlen(line);
		map->tab[tab_int[1]] = malloc(sizeof(char) * tab_int[0]);
		if (!map->tab[tab_int[1]])
			error("error malloc\n", map);
		while (tab_int[2] < (tab_int[0] - 1))
		{
			map->tab[tab_int[1]][tab_int[2]] = line[tab_int[2]];
			tab_int[2]++;
		}
		map->tab[tab_int[1]][tab_int[2]] = '\0';
		free(line);
		tab_int[1]++;
	}
	map->tab[tab_int[1]] = NULL;
}

static void	get_x(t_map *map)
{
	int	x;

	x = 0;
	while (map->tab[0][x])
		x++;
	map->size_x = x;
}

t_map	check_file(char *path_file)
{
	t_map	map;
	int		verif;
	int		fd;

	init_map(&map);
	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		error("file not exist\n", &map);
	verif = check_extension(path_file);
	if (verif == 1)
		error("not good extension\n", &map);
	create_map(fd, &map, path_file);
	close(fd);
	get_x(&map);
	return (map);
}
