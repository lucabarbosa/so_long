/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:02:11 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:59:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*result;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
	i++;
	}
	result[i] = '\0';
	return (result);
}
// static char upper(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (ft_toupper(c));
// 	return (c);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	char s[] = "hello";
// 	char *a;
// 	a = ft_strmapi(s, upper);
// 	printf("%s\n", a);
// 	if (a)
// 		free (a);
// 	return (0);
// }
