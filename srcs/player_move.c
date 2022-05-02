/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:09:13 by fardath           #+#    #+#             */
/*   Updated: 2022/05/02 21:14:19 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	print_step(t_game_map *map)
{
	char	*step;

	step = ft_itoa(map->steps);
	if (!map->game_over)
		ft_putstr_fd(step, 1);
	free(step);
}

static int	check_wall_move(t_game_map *map, int x, int y)
{
	int	line;
	int	count;

	line = 0;
	count = 0;
	if (map->map_data[y / TILE_WIDTH][x / TILE_WIDTH] == WALL)
		return (0);
	return (1);
}

static t_game_map	*move_y(t_game_map *map, int direction)
{
	int	x;
	int	y;

	x = map->player_position_x;
	y = map->player_position_y;
	if (check_wall_move(map, x, y + (TILE_WIDTH * direction)))
	{
		map->player_position_y += direction * TILE_WIDTH;
		map->steps++;
		print_step(map);
	}
	return (map);
}

static t_game_map	*move_x(t_game_map *map, int direction)
{
	int	x;
	int	y;

	x = map->player_position_x;
	y = map->player_position_y;
	if (check_wall_move(map, x + (TILE_WIDTH * direction), y))
	{
		map->player_position_x += direction * TILE_WIDTH;
		map->steps++;
		print_step(map);
	}
	return (map);
}

t_game_map	*get_wasd(t_game_map *map, int wasd)
{
	if (wasd == KEY_DOWN)
		return (move_y(map, 1));
	if (wasd == KEY_UP)
		return (move_y(map, -1));
	if (wasd == KEY_RIGHT)
		return (move_x(map, 1));
	if (wasd == KEY_LEFT)
		return (move_x(map, -1));
	return (map);
}