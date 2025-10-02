/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:58:29 by lbento            #+#    #+#             */
/*   Updated: 2025/10/02 01:14:01 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		update(t_game_manager *game);
static void	had_move(t_game_manager *game, int x, int y);
static void	iscollectable(t_game_manager *game);
static void	print_victory(t_game_manager *game);

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
			print_victory(game);
			free_game(game);
			exit(0);
		}
	}
}

static void	had_move(t_game_manager *game, int x, int y)
{
	if (game->game->player.x != x || game->game->player.y != y)
	{
		game->game->player_move++;
		ft_putstr_fd("Movement: ", 1);
		ft_putnbr_fd(game->game->player_move, 1);
		ft_putchar_fd('\n', 1);
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

static void	print_victory(t_game_manager *game)
{
	ft_putendl_fd("\033[1;32m", 1);
	ft_putendl_fd("╔══════════════════════════════════════════╗", 1);
	ft_putendl_fd("║                                          ║", 1);
	ft_putendl_fd("║\033[1;32m         ⭐  CONGRATULATIONS!  ⭐   \033[1;3]      ║", 1);
	ft_putendl_fd("║                                          ║", 1);
	ft_putendl_fd("║            YOU WON THE GAME!             ║", 1);
	ft_putendl_fd("║                                          ║", 1);
	ft_putstr_fd("║\033[1;36m            Total Moves: \033[1;32m", 1);
	if(game->game->player_move > 9 && game->game->player_move < 99)
	{
	ft_putnbr_fd(game->game->player_move, 1);
	ft_putendl_fd("\033[1;32m               ║", 1);
	}
	else if(game->game->player_move > 99)
	{
	ft_putnbr_fd(game->game->player_move, 1);
	ft_putendl_fd("\033[1;32m              ║", 1);
	}
	else
	{
	ft_putnbr_fd(game->game->player_move, 1);
	ft_putendl_fd("\033[1;32m                ║", 1);
	}
	ft_putendl_fd("║                                          ║", 1);
	ft_putendl_fd("╚══════════════════════════════════════════╝", 1);
	ft_putstr_fd("\033[0m", 1);
}
