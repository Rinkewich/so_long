/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wind_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:39:05 by fardath           #+#    #+#             */
/*   Updated: 2022/05/07 21:36:36 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	window_height(t_game_map *map)
{
	return (((map->map_height) + 1) * TILE_WIDTH);
}

int	window_length(t_game_map *map)
{
	return ((map->map_length) * TILE_WIDTH);
}

int	won_heignt(t_game_map *map)
{
	return ((((map->map_height) + 1) * TILE_WIDTH) / 2);
}

int	won_length(t_game_map *map)
{
	return (((map->map_length) * TILE_WIDTH) / 2);
}

void take_image_to_wind(t_game_map **map, t_render_v **vars)
{
	take_image_wall(vars, map);
	take_image_player(vars, map);
	take_image_count(vars, map);
	take_image_exit(vars, map);
	take_image_floor(vars, map);
}