/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:22:14 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:09 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	*test;
// 	test = ft_calloc(0, 2);
// 	printf("%n\n", test);
// 	free(test);
// 	return(0);
// }
