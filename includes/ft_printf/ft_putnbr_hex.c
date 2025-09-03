/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:49:20 by lbento            #+#    #+#             */
/*   Updated: 2025/08/06 11:31:37 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, int l_case);

int	ft_putnbr_hex(unsigned int nbr, int l_case)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_putnbr_hex(nbr / 16, l_case);
	}
	if (l_case == 0)
		write(1, &"0123456789abcdef"[nbr % 16], 1);
	else
		write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	i++;
	return (i);
}
