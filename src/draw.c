/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:41:07 by lbento            #+#    #+#             */
/*   Updated: 2025/10/02 00:35:20 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void			draw(t_game_manager *game);
static void	kind_draw(t_game_manager *game, int i, int j);

void	draw(t_game_manager *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->game->height)
	{
		x = 0;
		while (x < game->game->width)
		{
			kind_draw(game, x, y);
			x++;
		}
		y++;
	}
}

static void	kind_draw(t_game_manager *game, int i, int j)
{
		int	k;

	if (game->game->map[j][i] == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, i * 32, j * 32);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->ground, i * 32, j * 32);
	if (game->game->exit.x == i && game->game->exit.y == j)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit, i * 32, j * 32);
	k = 0;
	while (k < game->game->count_coll)
	{
		if (game->game->coll[k].x == i && game->game->coll[k].y == j)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->coll, i * 32, j * 32);
		k++;
	}
	if (game->game->player.x == i && game->game->player.y == j)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, i * 32, j * 32);
}
