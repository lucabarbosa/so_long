/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:43:22 by lbento            #+#    #+#             */
/*   Updated: 2025/09/23 19:30:46 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		convert_map(t_game_manager *game, char *file);
static void	coordinates(t_game_manager *game, char *file, int line, int position, int *collectables);
static void	free_matrix(t_game_manager *game, char *file, int **map, int size);

void	convert_map(t_game_manager *game, char *file)
{
	int	i;
	int	line;
	int	position;
	int	collectables;

	collectables = 0;
	position = 0;
	line = 0;
	while (line < game->game->height)
	{
		game->game->map[line] = (int *)malloc(sizeof(int) * game->game->width);
		if (!game->game->map[line])
			free_matrix(game, file, game->game->map, line);
		i = 0;
		while (i < game->game->width)
		{
			coordinates(game, &file[position], line, i, &collectables);
			game->game->map[line][i++] = file[position] - '0';
			position++;
	
		}
		position++;
		line++;
	}
}

static void	free_matrix(t_game_manager *game, char *file, int **map, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	game->game->map = 0;
	free(file);
	free_game(game);
	error_exit("convert_map -> malloc", errno);
}

static void	coordinates(t_game_manager *game, char *file, int line, int i, int *collectables)
{
	if (*file == 'P')
	{
		game->game->player.x = i;
		game->game->player.y = line;
		*file = '0';
	}
	else if (*file == 'E')
	{
		game->game->exit.x = i;
		game->game->exit.y = line;
		*file = '0';
	}
	else if (*file == 'C')
	{
		game->game->coll[*collectables].x = i;
		game->game->coll[*collectables].y = line;
		*file = '0';
		(*collectables)++;
	}
}
