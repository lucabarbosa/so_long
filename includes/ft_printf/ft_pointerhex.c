/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:24:21 by lbento            #+#    #+#             */
/*   Updated: 2025/08/06 11:12:40 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pointerhex(void *ptr);

static int	count_hexa(size_t address, int i);

static void	put_hexa(size_t address);

int	ft_pointerhex(void *ptr)
{
	size_t	address;
	int		i;

	i = 0;
	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	address = (size_t) ptr;
	i = ft_putstr_printf("0x");
	i = count_hexa(address, i);
	put_hexa(address);
	return (i);
}

static int	count_hexa(size_t address, int i)
{
	int	total;

	total = i;
	if (address == 0)
		return (1);
	while (address > 0)
	{
		address = address / 16;
		total++;
	}
	return (total);
}

static void	put_hexa(size_t address)
{
	if (address >= 16)
	{
		put_hexa(address / 16);
	}
	ft_putchar_printf("0123456789abcdef"[address % 16]);
}
