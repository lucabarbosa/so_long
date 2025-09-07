/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:31:42 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:08 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
// #include<stdio.h>
// int	main(void)
// {
// 	char mem_char[5] = "hello";
// 	int mem_int[3] = {1, 2 ,3};

// 	ft_bzero(mem_char, 5);
// 	printf("%s\n\n", mem_char);
// 	ft_bzero(mem_int, 12);
// 	printf("%d, %d, %d\n\n", mem_int[0], mem_int[1], mem_int[2]);
// }