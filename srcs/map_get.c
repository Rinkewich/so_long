/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:04 by fardath           #+#    #+#             */
/*   Updated: 2022/04/30 21:56:00 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
static int check_length(int *length, int height, char **map)
{
	int l_length;

	l_length = 0;
	height--;
	*length = ft_strlen(map[height]);
	(*length)++;
	while (height--)
	{
		
		l_length = ft_strlen(map[height]);
		if (l_length != *length)
			return (0);
	}
	return (1);
}
static int	open_file_map(char *argv, t_game_map *map, int *height)
{
	int	fd;

	*height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map_data = malloc(sizeof(char **) * 1);
	if (!(map->map_data))
		return (0);
	map->map_data[*height] = get_next_line(fd);
	while (map->map_data[*height] != NULL)
	{
		(*height)++;
		map->map_data[*height] = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	get_filename(char *argv)
{
	const char	*result;

	result = (const char *) &argv[(ft_strlen(argv) - 4)];
	if (ft_strncmp(result, ".ber", 4) == 0)
		return (0);
	else
		return (1);
}

void	get_map(int argc, char **argv, t_game_map *map)
{
	int	map_height;
	int	map_length;

	map = malloc(sizeof(t_game_map));
	if (get_filename(argv[1]) && !map)
		error("Invalid file name");
	if (!open_file_map(argv[1], map, &map_height))
		error("Internal error");
	if (!check_length(&map_length, map_height, map->map_data))
		error("Invalid map");
}
