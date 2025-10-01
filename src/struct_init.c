/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:14:12 by lbento            #+#    #+#             */
/*   Updated: 2025/10/01 14:43:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_manager	*struct_init(char *map);
static void		init_game(t_game_manager *game, char *map);
static void		init_render(t_game_manager *game);
static void		init_texture(t_game_manager *game);
static void		texture_load(t_game_manager *game, t_img **img, char *path);

t_game_manager	*struct_init(char *map)
{
	t_game_manager			*game;

	game = (t_game_manager *)malloc(sizeof(t_game_manager));
	if (!game)
		error_exit("struct_init -> malloc", errno);
	game->game = 0;
	game->mlx = 0;
	game->mlx_win = 0;
	game->mlx_img = 0;
	game->player = 0;
	game->exit = 0;
	game->coll = 0;
	game->wall = 0;
	game->ground = 0;
	init_game(game, map);
	init_render(game);
	init_texture(game);
	return (game);
}

void	init_game(t_game_manager *game, char *map)
{
	game->game = (t_map *)malloc(sizeof(t_map));
	if (!game->game)
	{
		free_game(game);
		error_exit("init_game -> malloc", errno);
	}
	game->game->map = 0;
	game->game->count_player = 0;
	game->game->coll = 0;
	game->game->count_coll = 0;
	game->game->count_exit = 0;
	game->game->player_move = 0;
	game->game->player_up = 0;
	game->game->player_down = 0;
	game->game->player_left = 0;
	game->game->player_right = 0;
	game->game->player_coll = 0;
	get_map(game, map);
}

static void	init_render(t_game_manager *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_game(game);
		error_exit("Can't load mlx", 0);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->game->width * 32,
			game->game->height * 32, "so_long");
	if (!game->mlx_win)
	{
		free_game(game);
		error_exit("Can't create a window", 0);
	}
	game->mlx_img = mlx_new_image(game->mlx, game->game->width * 32,
			game->game->height * 32);
	if (!game->mlx_img)
	{
		free_game(game);
		error_exit("Can't create an image", 0);
	}
}

static void	init_texture(t_game_manager *game)
{
	texture_load(game, &game->player, "./assets/player.xpm");
	texture_load(game, &game->exit, "./assets/exit.xpm");
	texture_load(game, &game->coll, "./assets/trophy.xpm");
	texture_load(game, &game->wall, "./assets/wall.xpm");
	texture_load(game, &game->ground, "./assets/ground.xpm");
}

static void	texture_load(t_game_manager *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*img == NULL)
	{
		free_game(game);
		error_exit("Can't load texture", errno);
	}
	(*img)->width = width;
	(*img)->height = height;
}
