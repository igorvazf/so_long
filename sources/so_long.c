/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:18 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/10/01 18:51:19 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (map_checker(&game))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			free_map(game.map);
			printf("Error\nInvalid Map");
			exit(1);
		}
	}
	else
	{
		printf("Error\nInvalid Sytax");
		exit(1);
	}
	return (0);
}
