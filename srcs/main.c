/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:13 by fardath           #+#    #+#             */
/*   Updated: 2022/05/02 20:40:17 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
void	ft_free_stuff(t_game_map **game_map, t_render_v **vars)
{
	static t_game_map	**game_mapm;
	static t_render_v	**varsm;
	int					maph;

	if (game_mapm && varsm && (!game_map && !vars))
	{
		maph = (*game_mapm)->map_height;
		free_map_data(*game_mapm);
		free((*game_mapm));
		free((*varsm));
		game_mapm = NULL;
		varsm = NULL;
	}
	if (game_map)
		game_mapm = game_map;
	if (vars)
		varsm = vars;
}
int	main(int argc, char **argv)
{
	t_game_map	*map;

	if (argc != 2)
		error("Incorrect number of arguments");
	if (!get_map(argc, argv, map))
		return (0);
	//ft_free_stuff(&map, NULL);
	if (!map)
		return(0);
	map->game_score = 0;
	map->game_over = 0;
	map->steps = 0;
	player_place(-1, map);
	return (1);
}
//