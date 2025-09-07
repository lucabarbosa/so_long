/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:49:23 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:13 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
//     int result;
//     result = ft_isascii('a');
//     printf("%d\n", result);
//     result = ft_isascii('6');
//     printf("%d\n", result);
//     result = ft_isascii(-1);
//     printf("%d\n", result);
//     result = ft_isascii(128);
//     printf("%d\n", result);
// }
