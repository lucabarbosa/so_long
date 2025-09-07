/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:20:12 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:59:49 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char copied[10];
// 	size_t total;
// 	total = ft_strlcpy(copied, "Hello", 10);
// 	printf("O tamano total é: %zu e a string copiada: %s\n", total, copied);
// 	total = ft_strlcpy(copied, "Hello", 4);
// 	printf("O tamano total é: %zu e a string copiada: %s\n", total, copied);
// 	total = ft_strlcpy(copied, "", 10);
// 	printf("O tamano total é: %zu e a string copiada: %s\n", total, copied);
// 	total = ft_strlcpy(copied, "Hello", 0);
// 	printf("O tamano total é: %zu e a string copiada: %s\n", total, copied);
// }
