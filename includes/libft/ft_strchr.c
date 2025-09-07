/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:03:26 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:58:44 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	int				i;
	const char		*str;

	str = s;
	cc = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == cc)
		return ((char *)&str[i]);
	return (NULL);
}
// #include <stdio.h>
// int main (void)
// {
// 	char *string = "tripouille";
// 	char *finded;

// 	finded = ft_strchr(string, 't' + 256);
// 	printf("%s", finded);
// }
