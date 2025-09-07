/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:47:01 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:53:50 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
// #include<stdio.h>
// int	main(void)
// {
// 	char mem_char[11] = "Hello";
// 	int mem_int[3] = {1, 2, 3};
// 	ft_memset(mem_char, 'A', 5);
// 	printf("%s\n\n", mem_char);
// 	ft_memset(mem_int, 0, 12);
// 	printf("%d, %d, %d\n", mem_int[0], mem_int[1], mem_int[2]);
// 	return (0);
// }