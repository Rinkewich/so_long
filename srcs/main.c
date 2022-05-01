/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:13 by fardath           #+#    #+#             */
/*   Updated: 2022/05/01 18:28:56 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	*map;

	if (argc != 2)
		error("Incorrect number of arguments");
	get_map(argc, argv, map);
	exit(1);
}
//