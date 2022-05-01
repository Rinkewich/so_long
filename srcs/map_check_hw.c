/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_hw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:52:52 by fardath           #+#    #+#             */
/*   Updated: 2022/05/01 21:20:53 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_length(int *length, int height, char **map)
{
	int	l_length;
	int	h_height;

	h_height = height;
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
	l_length--;
	if (l_length == h_height)
		return (0);
	return (1);
}

int	check_wall(int length, int height, char **map)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][length - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_player(t_game_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (y < map->map_height)
	{
		while (x < map->map_length)
		{
			if (map->map_data[y][x] == PLAYER)
			{
				count++;
				map->player_position_x = x;
				map->player_position_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void	check_map(t_game_map *map)
{
	if (!check_length((&map->map_length), map->map_height, map->map_data))
		error("Invalid map");
	if (!check_wall(map->map_length, map->map_height, map->map_data))
		error("Invalid wall");
	if (!check_player(map))
		error("Invalid player");
}
