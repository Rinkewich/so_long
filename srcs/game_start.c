/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:30:48 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 16:36:35 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	key_hook(int keycode, t_render_v **vars)
{	
	static t_game_map	*map;
	static t_render_v	*varsm;

	if ((*vars))
		varsm = (*vars);
	if (keycode == 53)
	{
		mlx_destroy_window((*vars)->mlx, (*vars)->win);
		free_stuff(NULL, NULL);
		exit(0);
		return (0);
	}
	if (varsm)
	{
		map = player_place(keycode, NULL);
		render_map(map, &varsm);
	}
	return (1);
}

static int	exit_hook(void)
{
	free_stuff(NULL, NULL);
	exit(0);
}

static int render(t_game_map *map, t_render_v *v)
{
	mlx_clear_window(v->mlx, v->win);
	render_map(map, &v);
	return(0);
}

static t_render_v	*init_window(t_game_map *map)
{
	t_render_v	*vars;
	int			w_length;
	int			w_height;

	vars = malloc(sizeof(t_render_v));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	w_length = window_length(map) - 100;
	w_height = window_height(map) - 100;
	vars->win = mlx_new_window(vars->mlx, w_length, w_height, "so_long");
	take_image_to_wind(&map, &vars);
	render_map(map, &vars);
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_hook(vars->win, 17, 0, exit_hook, &vars);
	mlx_loop_hook(vars->mlx, render, &vars);
	mlx_loop(vars->mlx);
	key_hook(-1, &vars);
	return (vars);
}

t_render_v	*start_game(t_game_map *map)
{
	t_render_v	*vars;

	vars = init_window(map);
	return (vars);
}
