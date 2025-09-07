/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:23 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 15:01:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c);

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}
// #include<stdio.h>
// int main(void)
// {
//     int result;
//         result = ft_toupper('a');
//     printf("%d\n", result);
//         result = ft_toupper('z');
//     printf("%d\n", result);
//         result = ft_toupper('A');
//     printf("%d\n", result);
//         result = ft_toupper('5');
//     printf("%d\n", result);
//         result = ft_toupper('#');
//     printf("%d\n", result);
// }
