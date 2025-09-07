/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:58:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*dest;

	size_s = ft_strlen(s) + 1;
	dest = (char *)malloc(size_s * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, (const void *)s, size_s);
	return (dest);
}
// #include <stdio.h>
// int main (void)
// {
// 	//char *str = "String copied";
// 	char *dup;

// 	dup = ft_strdup("");
// 	printf("%s\n", dup);
// 	free(dup);
// 	return (0);
// }