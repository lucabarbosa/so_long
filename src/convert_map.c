/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:43:22 by lbento            #+#    #+#             */
/*   Updated: 2025/09/30 18:39:42 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		convert_map(t_game_manager *game, char *file);
static void	coordinates(t_game_manager *game, char *file, int line, int pos);
static void	collectables(t_game_manager *game, int line, int i, int *collect);
static void	free_matrix(t_game_manager *game, char *file, int **map, int size);

void	convert_map(t_game_manager *game, char *file)
{
	int	i;
	int	line;
	int	pos;
	int	collect;

	collect = 0;
	pos = 0;
	line = 0;
	while (line < game->game->height)
	{
		game->game->map[line] = (int *)malloc(sizeof(int) * game->game->width);
		if (!game->game->map[line])
			free_matrix(game, file, game->game->map, line);
		i = 0;
		while (i < game->game->width)
		{
			if (file[pos] == 'C')
				collectables(game, line, i, &collect);
			coordinates(game, &file[pos], line, i);
			game->game->map[line][i++] = file[pos] - '0';
			pos++;
		}
		pos++;
		line++;
	}
}

static void	free_matrix(t_game_manager *game, char *file, int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	game->game->map = 0;
	free(file);
	free_game(game);
	error_exit("convert_map -> malloc", errno);
}

static void	collectables(t_game_manager *game, int line, int i, int *collect)
{
		game->game->coll[*collect].x = i;
		game->game->coll[*collect].y = line;
		(*collect)++;
}

static void	coordinates(t_game_manager *game, char *file, int line, int pos)
{
	if (*file == 'P')
	{
		game->game->player.x = pos;
		game->game->player.y = line;
		*file = '0';
	}
	else if (*file == 'E')
	{
		game->game->exit.x = pos;
		game->game->exit.y = line;
		*file = '0';
	}
	else if (*file == 'C')
	*file = '0';
}
