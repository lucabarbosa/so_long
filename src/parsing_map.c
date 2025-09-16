/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:43:22 by lbento            #+#    #+#             */
/*   Updated: 2025/09/15 23:49:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_map(t_game_manager *game, char *file);
static void	coordinates(t_game_manager *game, char *file, int k, int *obj);
static void	free_matrix(t_game_manager *game, char *file, int **m, int size);

void	parsing_map(t_game_manager *game, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < game->game->height)
	{
		game->game->map[j] = (int *)malloc(sizeof(int) * game->game->width);
		if (game->game->map[j] == 0)
			free_matrix(game, file, game->game->map, j);
		i = 0;
		while (i < game->game->width)
		{
			coordinates(game, file, k, &obj);
			game->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}

static void	free_matrix(t_game_manager *game, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	game->game->map = 0;
	free(file);
	root_destroy(game, "parsing_map -> malloc", errno);
}

static void	coordinates(t_game_manager *game, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		game->game->player.x = k % (game->game->width + 1);
		game->game->player.y = k / (game->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		game->game->exit.x = k % (game->game->width + 1);
		game->game->exit.y = k / (game->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		game->game->coll[*obj].x = k % (game->game->width + 1);
		game->game->coll[*obj].y = k / (game->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}
