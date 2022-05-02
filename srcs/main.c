/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:13 by fardath           #+#    #+#             */
/*   Updated: 2022/05/02 21:17:31 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
void	free_stuff(t_game_map *map, t_render_v *vars)
{
	static t_game_map	*mapm;
	static t_render_v	*varsm;
	int					maph;

	if (mapm && varsm && (!map && !vars))
	{
		maph = mapm->map_height;
		free_map_data(mapm);
		free(mapm);
		free(varsm);
		mapm = NULL;
		varsm = NULL;
	}
	if (map)
		mapm = map;
	if (vars)
		varsm = vars;
}
int	main(int argc, char **argv)
{
	t_game_map	map;

	if (argc != 2)
		error("Incorrect number of arguments");
	if (!get_map(argc, argv, &map))
		return (0);
	//free_stuff(&map, NULL);
	map.game_score = 0;
	map.game_over = 0;
	map.steps = 0;
	player_place(-1, &map);
	return (1);
}
//