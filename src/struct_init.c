/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:14:12 by lbento            #+#    #+#             */
/*   Updated: 2025/09/09 00:48:36 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_manager	*struct_init(char *map)
{
	t_game_manager			*game;

	game = (t_game_manager *)malloc(sizeof(t_game_manager));
	if (!game)
		{
			error_exit("struct_init() -> malloc()", errno);
			exit(1);
		}
	game->game = 0;
	game->mlx = 0;
	game->mlx_win = 0;
	game->mlx_img = 0;
	game->player = 0;
	game->exit = 0;
	game->coll = 0;
	game->wall = 0;
	game->ground = 0;
	game_init(game, map);
	renderer_init(game);
	texture_init(game);
	return (game);
}
