/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:22:28 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:07 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	total;
	int	signal;

	total = 0;
	i = 0;
	signal = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		signal *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
			total = (nptr[i] - '0') + (total * 10);
		i++;
	}
	return (total * signal);
}
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char *str = "       -42";
// 	int	result;
// 	int true_atoi;

// 	result = ft_atoi(str);
// 	true_atoi = atoi(str);
// 	printf("%d\n", result);
// 	printf("%d\n", true_atoi);
// 	return (0);
// }