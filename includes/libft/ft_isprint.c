/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:10:26 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c);

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
//     int result;
//     result = ft_isprint('a');
//     printf("%d\n", result);
//     result = ft_isprint('6');
//     printf("%d\n", result);
//     result = ft_isprint('\n');
//     printf("%d\n", result);
//     result = ft_isprint(31);
//     printf("%d\n", result);
// }