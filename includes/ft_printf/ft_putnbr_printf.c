/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:51:08 by lbento            #+#    #+#             */
/*   Updated: 2025/08/06 11:21:21 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int nbr);

int	ft_putnbr_printf(int nbr)
{
	int	i;

	i = 0;
	if (nbr < -2147483647)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{	
		nbr = -nbr;
		write(1, "-", 1);
		i++;
	}
	if (nbr > 9)
	{
		i += ft_putnbr_printf(nbr / 10);
	}
	write(1, &"0123456789"[nbr % 10], 1);
	i++;
	return (i);
}
