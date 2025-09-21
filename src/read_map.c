/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:02:53 by lbento            #+#    #+#             */
/*   Updated: 2025/09/21 15:35:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		read_map(t_game_manager *game, char *file);
static void	width_map(t_game_manager *game, char *file);
static void	height_map(t_game_manager *game, char *file);

void	read_map(t_game_manager *game, char *file)
{
	width_map(game, file);
	height_map(game, file);
	map_valid(game, file);
	game->game->coll = (t_coord *)malloc
		(sizeof(t_coord) * game->game->count_coll);
	if (game->game->coll == 0)
	{
		free(file);
		free_game(game);
		error_exit("parsing_map -> malloc", errno);
	}
	game->game->map = (int **)malloc(sizeof(int *) * game->game->height);
	if (game->game->map == 0)
	{
		free(file);
		free_game(game);
		error_exit("parsing_map -> malloc", errno);
	}
	parsing_map(game, file);
}

static void	width_map(t_game_manager *game, char *file)
{
	game->game->width = 0;
	while (file[game->game->width] && file[game->game->width] != '\n')
		game->game->width++;
	if (game->game->width == 0 || file[game->game->width] == 0)
	{
		free(file);
		free_game(game);
		error_exit("Map used is invalid", 0);
	}
}

static void	height_map(t_game_manager *game, char *file)
{
	int				i;
	int				j;

	game->game->height = 1;
	i = game->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (game->game->width != j)
		{
			free(file);
			free_game(game);
			error_exit("map format is invalid", 0);
		}
		i += game->game->width + 1;
		game->game->height++;
	}
}
