/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:24:46 by fardath           #+#    #+#             */
/*   Updated: 2022/05/07 21:30:54 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_put_img(t_render_v **vars, void *p, int x, int y)
{
	if ((*vars) && p)
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, p, x, y);
}

void set_count(int size[], int number[])
{
	size[0] = 0;
	size[1] = 0;
	number[0] = 0;
	number[1] = 0;
}

void xpm(char letter, t_render_v **v, int size[], t_game_map **map)
{
	ft_put_img(v, (*map)->floor, size[0], size[1]);
	if (letter == WALL)
		ft_put_img(v, (*map)->wall, size[0], size[1]);
	if (letter == COUNT)
		ft_put_img(v, (*map)->items, size[0], size[1]);
	if (letter == EXIT)
		ft_put_img(v, (*map)->exit, size[0], size[1]);
}