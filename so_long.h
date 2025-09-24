/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:01:28 by lbento            #+#    #+#             */
/*   Updated: 2025/09/24 16:09:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx/mlx_int.h>
# include "libft/libft.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_map
{
	int				**map;
	t_coord			player;
	int				count_player;
	t_coord			*coll;
	int				count_coll;
	t_coord			exit;
	int				count_exit;
	int				height;
	int				width;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
}				t_map;

typedef struct s_game_manager
{
	void			*mlx;
	void			*mlx_win;
	t_map			*game;
	t_img			*mlx_img;
	t_img			*player;
	t_img			*coll;
	t_img			*ground;
	t_img			*wall;
	t_img			*exit;
}				t_game_manager;

void			draw(t_game_manager *game);
void			game_destroy(t_map *game);
t_game_manager	*struct_init(char *map);
void			free_game(t_game_manager *struct_game);
void			init_map(t_game_manager *game, char *map);
void			init_game(t_game_manager *game, char *map);
int			solvable(t_game_manager *game);
void			handling_map(t_game_manager *game, char *file);
void			map_valid(t_game_manager *game, char *file);
void			convert_map(t_game_manager *game, char *file);
void			error_exit(char *error_message, int error_number);

#endif
