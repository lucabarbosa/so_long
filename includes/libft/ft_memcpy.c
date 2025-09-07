/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:44:36 by lbento            #+#    #+#             */
/*   Updated: 2025/07/30 15:38:26 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*copied;
	unsigned char		*pasted;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	copied = (const unsigned char *)src;
	pasted = (unsigned char *)dest;
	while (i < n)
	{
		pasted[i] = copied[i];
		i++;
	}
	return (dest);
}
//  #include <stdio.h>
//  int	main(void)
//  {
//  	char source[1] = "\0";
//  	char dest[1];

//  	ft_memcpy(dest, source, 1);
//  	printf("%s\n", dest);
//  }