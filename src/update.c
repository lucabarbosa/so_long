/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:58:29 by lbento            #+#    #+#             */
/*   Updated: 2025/09/30 15:32:33 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	had_move(t_game_manager *game, int x, int y)
{
	if (game->game->player.x != x || game->game->player.y != y)
	{
		game->game->player_move++;
		ft_putnbr_fd(game->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_game_manager *game)
{
	int				k;

	k = 0;
	while (k < game->game->count_coll)
	{
		if (game->game->coll[k].x == game->game->player.x
			&& game->game->coll[k].y == game->game->player.y)
		{
			game->game->coll[k].x = -1;
			game->game->coll[k].y = -1;
			game->game->player_coll++;
		}
		k++;
	}
}

void	update(t_game_manager *game)
{
	int				x;
	int				y;

	x = game->game->player.x;
	y = game->game->player.y;
	if (game->game->player_up != 0)
		move_up(game, x, y);
	else if (game->game->player_down != 0)
		move_down(game, x, y);
	else if (game->game->player_left != 0)
		move_left(game, x, y);
	else if (game->game->player_right != 0)
		move_right(game, x, y);
	had_move(game, x, y);
	iscollectable(game);
	draw(game);
	if (game->game->exit.x == game->game->player.x
		&& game->game->exit.y == game->game->player.y)
	{
		if (game->game->count_coll == game->game->player_coll)
		{
			free_game(game);
			exit(0);
		}
	}
}
