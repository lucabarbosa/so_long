/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:42:58 by lbento            #+#    #+#             */
/*   Updated: 2025/09/23 19:49:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	dotber(char *map);

int	main(int argc, char *argv[])
{
	t_game_manager	*game;

	if (argc != 2)
		error_exit("Invalid number of arguments!\n", 0);
	if (dotber(argv[1]) == 1)
		error_exit("Invalid map extension. The map must be <.ber>\n", 0);
	game = struct_init(argv[1]);
	drawing(game);
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
