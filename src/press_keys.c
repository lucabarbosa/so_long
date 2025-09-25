/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:53:33 by lbento            #+#    #+#             */
/*   Updated: 2025/09/25 14:51:06 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int pressed_key, t_game_manager *game);
int	key_release(int pressed_key, t_game_manager *game);
int	destroy_hook(int pressed_key, t_game_manager *game);

int	key_pressed(int pressed_key, t_game_manager *game)
{
	if (pressed_key == 65307)
	{
		free_game(game);
		exit(0);
	}
	if (pressed_key == 119)
		game->game->player_up = 1;
	if (pressed_key == 115)
		game->game->player_down = 1;
	if (pressed_key == 97)
		game->game->player_left = 1;
	if (pressed_key == 100)
		game->game->player_right = 1;
	update(game);
	return (0);
}

int	key_release(int pressed_key, t_game_manager *game)
{
	if (pressed_key == 119)
		game->game->player_up = 0;
	if (pressed_key == 115)
		game->game->player_down = 0;
	if (pressed_key == 97)
		game->game->player_left = 0;
	if (pressed_key == 100)
		game->game->player_right = 0;
	update(game);
	return (0);
}

int	destroy_hook(int pressed_key, t_game_manager *game)
{
	(void)pressed_key;
	(void)game;
	free_game(game);
	exit(0);
	return (0);
}
