/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:22:14 by lbento            #+#    #+#             */
/*   Updated: 2025/10/01 15:08:58 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_destroy(t_map *game);
void	error_exit(char *error_message, int error_number);
void	free_game(t_game_manager *game);

void	free_game(t_game_manager *game)
{
	if (game != 0)
	{
		if (game->player != 0)
			mlx_destroy_image(game->mlx, game->player);
		if (game->coll != 0)
			mlx_destroy_image(game->mlx, game->coll);
		if (game->ground != 0)
			mlx_destroy_image(game->mlx, game->ground);
		if (game->wall != 0)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->exit != 0)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->mlx_img != 0)
			mlx_destroy_image(game->mlx, game->mlx_img);
		if (game->mlx_win != 0)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx != 0)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->game != 0)
			game_destroy(game->game);
		free(game);
	}
}

void	game_destroy(t_map *game)
{
	int				i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
		}
		free(game);
	}
}

void	error_exit(char *error_message, int error_number)
{
	ft_putendl_fd("Error:", 2);
	ft_putstr_fd(error_message, 2);
	if (error_number != 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(error_number), 2);
	}
	ft_putchar_fd('\n', 2);
	exit(1);
}
