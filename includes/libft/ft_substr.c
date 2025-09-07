/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:11:16 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 15:01:04 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	ft_substr_len(unsigned int start, size_t len, size_t s_len)
{
	size_t	total;

	total = len;
	if (start + len > s_len)
		total = s_len - start;
	return (total);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;
	size_t	substr_len;

	len_s = ft_strlen(s);
	if (start >= len_s || len == 0)
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	substr_len = ft_substr_len(start, len, len_s);
	substr = (char *)malloc(substr_len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *result;
// 	result = ft_substr("Hello, World!", 7, 5);
// 	printf("Teste 1: %s\n", result);
// 	free(result);
// 	result = ft_substr("Hello World!", 1, 3);
// 	printf("Teste 2: %s\n", result);
// 	free(result);
// 	result = ft_substr("Hello World!", 28, 3);
// 	printf("Teste 3: %s\n", result);
// 	free(result);
// 	result = ft_substr(0, 0, 3);
// 	printf("Teste 4: %s\n", result);
// 	free(result);
// 	return (0);
// }
