/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:03:50 by lbento            #+#    #+#             */
/*   Updated: 2025/09/25 14:17:57 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	solvable(t_game_manager *game);
static int	**copy_map(t_game_manager *game);
static void	free_map_copy(int **map_copy, int height);
static void	flood_fill(int **map, int x, int y, t_game_manager *game);

int	solvable(t_game_manager *game)
{
	int	**map_copy;
	int	i;

	map_copy = copy_map(game);
	if (!map_copy)
		return (1);
	flood_fill(map_copy, game->game->player.x, game->game->player.y, game);
	if (map_copy[game->game->exit.y][game->game->exit.x] != 2)
	{
		free_map_copy(map_copy, game->game->height);
		return (1);
	}
	i = 0;
	while (i < game->game->count_coll)
	{
		if (map_copy[game->game->coll[i].y][game->game->coll[i].x] != 2)
		{
			free_map_copy(map_copy, game->game->height);
			return (1);
		}
		i++;
	}
	free_map_copy(map_copy, game->game->height);
	return (0);
}

static int	**copy_map(t_game_manager *game)
{
	int	**map_copy;
	int	i;

	map_copy = (int **)malloc(sizeof(int *) * game->game->height);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->game->height)
	{
		map_copy[i] = (int *)malloc(sizeof(int) * game->game->width);
		if (!map_copy[i])
		{
			while (i-- >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
	ft_memcpy(map_copy[i], game->game->map[i], sizeof(int) * game->game->width);
		i++;
	}
	return (map_copy);
}

static void	flood_fill(int **map, int x, int y, t_game_manager *game)
{
	if (x < 0 || x >= game->game->width || y < 0 || y >= game->game->height
		|| map[y][x] != 0)
		return ;
	
	map[y][x] = 2;
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static void	free_map_copy(int **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
