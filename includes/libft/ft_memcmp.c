/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:31:07 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:50:29 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int result;

// 	result = ft_memcmp("Hello World", "Hello", 5);
// 	printf("Teste 1: %d\n", result);

// 	result = ft_memcmp("Hello World", "World", 15);
// 	printf("Teste 1: %d\n", result);

// 	result = ft_memcmp("Hello World", "abc", 10);
// 	printf("Teste 1: %d\n", result);
// }
