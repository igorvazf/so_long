/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:06 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/10/02 23:46:43 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PA.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PA.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
