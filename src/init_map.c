/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:19:35 by lbento            #+#    #+#             */
/*   Updated: 2025/09/19 14:59:03 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		init_map(t_game_manager *game, char *map);
static void	read_file(t_game_manager *game, char **file, char buf[], int fd);
static void	file_join(t_game_manager *game, char **file, char buf[], int fd);

void	init_map(t_game_manager *game, char *map)
{
	int				fd;
	char			*file;
	char			buf[1025];

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		free_game(game);
		error_exit(map, errno);
	}
	file = ft_calloc(1, 1);
	if (!file)
	{		
		free_game(game);
		close(fd);
		error_exit("init_map -> calloc", errno);
	}
	read_file(game, &file, buf, fd);
	close(fd);
	read_map(game, file);
	free(file);
}

static void	read_file(t_game_manager *game, char **file, char buf[], int fd)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, 1024);
		if (bytes_read == -1)
		{
			free(*file);
			close(fd);
			free_game(game);
			error_exit("init_map -> read", errno);
		}
		else
		{
			buf[bytes_read] = 0;
			file_join(game, file, buf, fd);
		}
	}
}

static void	file_join(t_game_manager *game, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		free_game(game);
		error_exit("init_map -> ft_strjoin", errno);
	}
}
