/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:45:45 by fardath           #+#    #+#             */
/*   Updated: 2022/05/02 21:13:53 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static t_game_map	*check_tile(t_game_map *map)
{
	int	x;
	int	y;

	y = map->player_position_y / TILE_WIDTH;
	x = map->player_position_x / TILE_WIDTH;
	if (map->map_data[y][x] == 'C')
	{
		map->map_data[y][x] = '0';
		map->game_score++;
	}
	return (map);
}
void	find_player(t_game_map *map, int *x, int *y)
{
	int		count;
	char	*line;
	int		xPos;

	count = 0;
	xPos = 0;
	while (count < map->map_height)
	{
		line = map->map_data[count];
		if (ft_strchr(line, 'P'))
		{
			*y = (count * TILE_WIDTH);
			while (line[xPos] != 'P')
				xPos++;
			*x = (xPos * TILE_WIDTH);
		}
		count++;
	}
}
t_game_map	*player_place(int wasd, t_game_map *f_map)
{
	static t_game_map	*map;
	static int			game_end = 0;

	if (map && (game_end == 0))
	{
		map = get_wasd(map, wasd);
		map = check_tile(map);
	}
	else if (f_map && (game_end == 0))
	{
		map = f_map;
		if (f_map->game_over)
			game_end = 1;
		else
			find_player(map, &map->player_position_x,
				&map->player_position_y);
	}
	return (map);
}