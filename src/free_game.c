/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:22:14 by lbento            #+#    #+#             */
/*   Updated: 2025/09/19 14:57:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_destroy(t_map *game);
void	error_exit(char *error_message, int error_number);
void	free_game(t_game_manager *struct_game);

void	free_game(t_game_manager *struct_game)
{
	if (struct_game != 0)
	{
		if (struct_game->player != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->player);
		if (struct_game->coll != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->coll);
		if (struct_game->ground != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->ground);
		if (struct_game->wall != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->wall);
		if (struct_game->exit != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->exit);
		if (struct_game->mlx_img != 0)
			mlx_destroy_image(struct_game->mlx, struct_game->mlx_img);
		if (struct_game->mlx_win != 0)
			mlx_destroy_window(struct_game->mlx, struct_game->mlx_win);
		if (struct_game->mlx != 0)
			mlx_destroy_display(struct_game->mlx);
		if (struct_game->game != 0)
			game_destroy(struct_game->game);
		free(struct_game);
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
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}

void	error_exit(char *error_message, int error_number)
{
	ft_putendl_fd("Return error:", 2);
	ft_putstr_fd(error_message, 2);
	if (error_number != 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(error_number), 2);
	}
	exit(1);
}
