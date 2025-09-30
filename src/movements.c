/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:34:55 by lbento            #+#    #+#             */
/*   Updated: 2025/09/30 18:38:45 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_manager *game, int x, int y)
{
	if (game->game->map[y - 1][x] == 0)
		game->game->player.y -= 1;
}

void	move_down(t_game_manager *game, int x, int y)
{
	if (game->game->map[y + 1][x] == 0)
		game->game->player.y += 1;
}

void	move_left(t_game_manager *game, int x, int y)
{
	if (game->game->map[y][x - 1] == 0)
		game->game->player.x -= 1;
}

void	move_right(t_game_manager *game, int x, int y)
{
	if (game->game->map[y][x + 1] == 0)
		game->game->player.x += 1;
}
