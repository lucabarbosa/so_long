/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:35:28 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:54:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// int	main(void)
// {
// 	ft_putchar_fd('a', 1);
// 	ft_putchar_fd('A', 2);
// 	ft_putchar_fd('\t', 1);
// 	ft_putchar_fd('a', 42);
// 	return (0);
// }