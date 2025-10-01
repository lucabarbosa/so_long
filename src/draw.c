/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:41:07 by lbento            #+#    #+#             */
/*   Updated: 2025/10/01 15:56:35 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void			draw(t_game_manager *game);
static void		square_map(t_game_manager *game, t_img *img, int x, int y);
static void		draw_env(t_game_manager *game, int i, int j);

void	draw(t_game_manager *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->game->height)
	{
		i = 0;
		while (i < game->game->width)
		{
			if (game->game->map[j][i] == 1)
				square_map(game, game->wall, i * 32, j * 32);
			else
				square_map(game, game->ground, i * 32, j * 32);
			draw_env(game, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}

static void	square_map(t_game_manager *game, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_game_manager *game, int i, int j)
{
	int	k;

	if (game->game->exit.x == i && game->game->exit.y == j)
		square_map(game, game->exit, i * 32, j * 32);
	k = 0;
	while (k < game->game->count_coll)
	{
		if (game->game->coll[k].x == i && game->game->coll[k].y == j)
			square_map(game, game->coll, i * 32, j * 32);
	k++;
	}
	if (game->game->player.x == i && game->game->player.y == j)
		square_map(game, game->player, i * 32, j * 32);
}
