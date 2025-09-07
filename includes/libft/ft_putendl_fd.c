/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:50:08 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:54:01 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
	i++;
	}
	write(fd, "\n", 1);
}
// int	main(void)
// {
// 	ft_putstr_fd("", 1);
// 	ft_putstr_fd("Error", 2);
// 	ft_putstr_fd("\nHello \t World", 1);
// 	ft_putstr_fd("Hello World", 42);
// 	return (0);
// }
