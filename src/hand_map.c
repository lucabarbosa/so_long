/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:58:55 by lbento            #+#    #+#             */
/*   Updated: 2025/09/30 21:17:43 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		handling_map(t_game_manager *game, char *file);
static void	width_map(t_game_manager *game, char *file);
static void	height_map(t_game_manager *game, char *file);

void	handling_map(t_game_manager *game, char *file)
{
	width_map(game, file);
	height_map(game, file);
	map_valid(game, file);
	game->game->coll = (t_coord *)malloc
		(sizeof(t_coord) * game->game->count_coll);
	if (!game->game->coll)
	{
		free(file);
		free_game(game);
		error_exit("Collectables -> malloc", errno);
	}
	game->game->map = (int **)malloc(sizeof(int *) * game->game->height);
	if (!game->game->map)
	{
		free(file);
		free_game(game);
		error_exit("handling_map -> malloc", errno);
	}
	convert_map(game, file);
	if (solvable(game) == 1)
	{
		free(file);
		free_game(game);
		error_exit("Map isn't resolvable.", 0);
	}
}

static void	width_map(t_game_manager *game, char *file)
{
	game->game->width = 0;
	while (file[game->game->width] && file[game->game->width] != '\n')
		game->game->width++;
	if (game->game->width == 0 || file[game->game->width] == '\0')
	{
		free(file);
		free_game(game);
		error_exit("Map used is invalid", 0);
	}
}

static void	height_map(t_game_manager *game, char *file)
{
	int				count_line;
	int				width_size;

	game->game->height = 1;
	count_line = game->game->width + 1;
	while (file[count_line] != '\0')
	{
		width_size = 0;
		while (file[count_line + width_size] != '\0'
			&& file[count_line + width_size] != '\n')
			width_size++;
		if (game->game->width != width_size)
		{
			free(file);
			free_game(game);
			error_exit("The map isn't rectangular", 0);
		}
		count_line += width_size + 1;
		game->game->height++;
	}
}
