/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:26:43 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 15:01:09 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c +32);
	return (c);
}
// #include<stdio.h>
// int main(void)
// {
//     int result;
//         result = ft_tolower('a');
//     printf("%d\n", result);
//         result = ft_tolower('z');
//     printf("%d\n", result);
//         result = ft_tolower('A');
//     printf("%d\n", result);
//         result = ft_tolower('5');
//     printf("%d\n", result);
//         result = ft_tolower('#');
//     printf("%d\n", result);
// }
