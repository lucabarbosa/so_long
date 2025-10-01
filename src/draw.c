/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:41:07 by lbento            #+#    #+#             */
/*   Updated: 2025/10/01 20:05:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void			draw(t_game_manager *game);
static void		square_map(t_game_manager *game, t_img *img, int x, int y);
static void		draw_env(t_game_manager *game, int x, int y);

void	draw(t_game_manager *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->game->height)
	{
		x = 0;
		while (x < game->game->width)
		{
			if (game->game->map[y][x] == 1)
				square_map(game, game->wall, x * 32, y * 32);
			else
				square_map(game, game->ground, x * 32, y * 32);
			draw_env(game, x, y);
			x++;
		}
		y++;
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

static void	draw_env(t_game_manager *game, int x, int y)
{
	int	k;

	if (game->game->exit.x == x && game->game->exit.y == y)
		square_map(game, game->exit, x * 32, y * 32);
	k = 0;
	while (k < game->game->count_coll)
	{
		if (game->game->coll[k].x == x && game->game->coll[k].y == y)
			square_map(game, game->coll, x * 32, y * 32);
	k++;
	}
	if (game->game->player.x == x && game->game->player.y == y)
		square_map(game, game->player, x * 32, y * 32);
}
