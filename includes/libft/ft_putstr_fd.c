/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:45:21 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:55:08 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
	i++;
	}
}
// int	main(void)
// {
// 	ft_putstr_fd("", 1);
// 	ft_putstr_fd("Error", 2);
// 	ft_putstr_fd("\nHello \t World", 1);
// 	ft_putstr_fd("Hello World", 42);
// 	return (0);
// }
