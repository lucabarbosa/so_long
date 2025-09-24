/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:03:50 by lbento            #+#    #+#             */
/*   Updated: 2025/09/24 16:08:59 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			solvable(t_game_manager *game);
static void	flood_fill(t_game_manager *game, int x, int y);

int	solvable(t_game_manager *game)
{
	int	i;

	flood_fill(game, game->game->player.x, game->game->player.y);
	if (game->game->map[game->game->exit.y][game->game->exit.x] != 2)
		return (1);
	i = 0;
	while (i < game->game->count_coll)
	{
		if (game->game->map[game->game->coll[i].y][game->game->coll[i].x] != 2)
			return (1);
	i++;
	}
	return (0);
}

static void	flood_fill(t_game_manager *game, int x, int y)
{
	if (x < 0 || x >= game->game->width || y < 0 || y >= game->game->height
		|| game->game->map[y][x] != 0)
		return ;
	game->game->map[y][x] = 2;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
