/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:57:11 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
// #include<stdio.h>
// int main (void)
// {
//     int result;
//     result = ft_isdigit('9');
//     printf("%d\n", result);
// }
