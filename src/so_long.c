/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:42:58 by lbento            #+#    #+#             */
/*   Updated: 2025/10/01 20:05:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	dotber(char *map);

int	main(int argc, char *argv[])
{
	t_game_manager	*game;

	if (argc != 2)
		error_exit("Invalid number of arguments!", 0);
	if (dotber(argv[1]) == 1)
		error_exit("Invalid map. The map must be <.ber>.", 0);
	game = struct_init(argv[1]);
	draw(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_released, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, destroy_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

static int	dotber(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map == 0)
		return (1);
	if (len < 5)
		return (1);
	if (ft_strcmp((map + len - 4), ".ber") != 0)
		return (1);
	return (0);
}
