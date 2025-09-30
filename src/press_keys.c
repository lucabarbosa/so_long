/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:53:33 by lbento            #+#    #+#             */
/*   Updated: 2025/09/30 20:26:11 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_game_manager *game);
int	key_released(int keycode, t_game_manager *game);
int	destroy_hook(int keycode, t_game_manager *game);

int	key_pressed(int keycode, t_game_manager *game)
{
	if (keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	if (keycode == 119 || keycode == 65362)
		game->game->player_up = 1;
	if (keycode == 115 || keycode == 65364)
		game->game->player_down = 1;
	if (keycode == 97 || keycode == 65361)
		game->game->player_left = 1;
	if (keycode == 100 || keycode == 65363)
		game->game->player_right = 1;
	update(game);
	return (0);
}

int	key_released(int keycode, t_game_manager *game)
{
	if (keycode == 119 || keycode == 65362)
		game->game->player_up = 0;
	if (keycode == 115 || keycode == 65364)
		game->game->player_down = 0;
	if (keycode == 97 || keycode == 65361)
		game->game->player_left = 0;
	if (keycode == 100 || keycode == 65363)
		game->game->player_right = 0;
	update(game);
	return (0);
}

int	destroy_hook(int keycode, t_game_manager *game)
{
	free_game(game);
	exit(0);
	(void)keycode;
	(void)game;
}
