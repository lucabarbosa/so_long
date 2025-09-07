/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:49:45 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 15:00:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n - 1 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
// #include<stdio.h>
// int	main(void)
// {
// 	char *s1 = "Hello";
// 	char *s2= "Hello";
// 	int result;
// 	printf("%d\n", result = ft_strncmp(s1, s2, 0));
// }
