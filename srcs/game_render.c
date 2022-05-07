/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:23:26 by fardath           #+#    #+#             */
/*   Updated: 2022/05/07 21:33:55 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	game_end(t_game_map *game_map)
{
	return (game_map->max_score == game_map->game_score);
}

static int	game_won(t_game_map **map, t_render_v **v, int *won)
{
	(*map)->game_over = 1;
	mlx_string_put((*v)->mlx, (*v)->win, won[1], won[0], BLUE, GAME_WON);
	player_place(-2, (*map));
	return (1);
}

int	game_over(t_game_map **map, t_render_v **vars)
{
	int	x;
	int	y;
	int	won[2];

	won[0] = won_heignt(*map);
	won[1] = won_length(*map);
	y = (*map)->player_position_y;
	x = (*map)->player_position_x;
	y = (*map)->player_position_y;
	if ((*map)->map_data[x][y] == 'E' && game_end((*map)))
		return (game_won(map, vars, won));
	return (0);
}

static void	put_image_to_map(t_game_map *map, t_render_v **v)
{
	int 	size[2];
	int		num[2];
	char	letter;

	size[0] = 0;
	size[1] = 0;
	num[0] = 0;
	num[1] = 0;
	while (num[0] < map->map_height && v)
	{
		while (map->map_data[num[0]][num[1]] != 0)
		{
			letter = map->map_data[num[0]][num[1]];
			xpm(letter, v, size, &map);
			num[1]++;
			size[0] += TILE_WIDTH;
		}
		size[1] += TILE_WIDTH;
		size[0] = 0;
		num[0]++;
		num[1] = 0;
	}
}
void	render_map(t_game_map *map, t_render_v **vars)
{
	if (!game_over(&map, vars))
	{
		put_image_to_map(map, vars);
	}
}
