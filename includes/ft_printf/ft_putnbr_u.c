/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:58:10 by lbento            #+#    #+#             */
/*   Updated: 2025/08/06 11:23:21 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr);

int	ft_putnbr_u(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 10)
	{
		i += ft_putnbr_u(nbr / 10);
	}
	write(1, &"0123456789"[nbr % 10], 1);
	i++;
	return (i);
}
