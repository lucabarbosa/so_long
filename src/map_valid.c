/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:22:10 by lbento            #+#    #+#             */
/*   Updated: 2025/09/24 01:43:13 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void			map_valid(t_game_manager *game, char *file);
static int		isborder(t_game_manager *game, int i);
static void		is_pec(t_game_manager *game, char *file, int i);
static void		verify_map(t_game_manager *game, char *file);
static int	map_is_solvable(t_game_manager *game);

void	map_valid(t_game_manager *game, char *file)
{
	int				i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			i++;
		if (file[i] == '\0')
			break ;
		if (isborder(game, i))
		{
			if (file[i] != '1')
			{
				free(file);
				free_game(game);
				error_exit("Map isn't surrounded by walls.", 0);
			}
		}
		else
			is_pec(game, file, i);
	i++;
	}
	verify_map(game, file);
}

static int	isborder(t_game_manager *game, int i)
{
	if (i < game->game->width
		|| i % (game->game->width + 1) == 0
		|| i % (game->game->width + 1) == game->game->width - 1
		|| i > (game->game->width + 1) * (game->game->height - 1))
		return (1);
	return (0);
}

static void	is_pec(t_game_manager *game, char *file, int i)
{
	if (file[i] == 'P')
		game->game->count_player++;
	else if (file[i] == 'E')
		game->game->count_exit++;
	else if (file[i] == 'C')
		game->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		free_game(game);
		error_exit("The map content doesn't follow the rules.", 0);
	}
}

static void	verify_map(t_game_manager *game, char *file)
{
	if (game->game->count_player != 1
		|| game->game->count_exit != 1
		|| game->game->count_coll < 1)
	{
		free(file);
		free_game(game);
		error_exit("Map configuration not allowed.", 0);
	}
	if (map_is_solvable(game) == 1)
	{
		free(file);
		free_game(game);
		error_exit("Map isn't resolvable.", 0);
	}
}

static int	map_is_solvable(t_game_manager *game)
{
	
}