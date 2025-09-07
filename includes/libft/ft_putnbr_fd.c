/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:57:43 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:54:25 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -2147483647)
		write(fd, "-2147483648", 10);
	else if (n < 0)
	{	
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}
// int	main(void)
// {
// 	ft_putnbr_fd(42,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-42,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647,1);
// 	return (0);
// }