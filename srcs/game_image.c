/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:59:42 by fardath           #+#    #+#             */
/*   Updated: 2022/05/07 19:29:13 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void take_image_floor(t_render_v **vars, t_game_map **map)
{
	char		*name;
	static void	*img;
	int			pos[2];

	name = FLOOR_XPM;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, PLAYER_XPM, &pos[0], &pos[1]);
	(*map)->floor = img;
}

void take_image_exit(t_render_v **vars, t_game_map **map)
{
	char		*name;
	static void	*img;
	int			pos[2];

	name = EXIT_XPM;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, name, &pos[0], &pos[1]);
	(*map)->exit = img;
}

void take_image_count(t_render_v **vars, t_game_map **map)
{
	char		*name;
	static void	*img;
	int			pos[2];

	name = COUNT_XPM;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, name, &pos[0], &pos[1]);
	(*map)->items = img;
}

void take_image_player(t_render_v **vars, t_game_map **map)
{
	char		*name;
	static void	*img;
	int			pos[2];

	name = PLAYER_XPM;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, name, &pos[0], &pos[1]);
	(*map)->player = img;
}

void take_image_wall(t_render_v **vars, t_game_map **map)
{
	char		*name;
	static void	*img;
	int			pos[2];

	name = WALL_XPM;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, name, &pos[0], &pos[1]);
	(*map)->items = img;
}