/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:53:31 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 15:00:48 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
// #include <stdio.h>
// int main (void)
// {
// 	char *string = "tripouille";
// 	char *finded;
// 	finded = ft_strrchr(string, 't');
// 	printf("\n%s\n\n", finded);
// 	finded = ft_strrchr(string, 0);
// 	printf("%s\n\n", finded);
// 	finded = ft_strrchr(string, '\n');
// 	printf("%s", finded);
// }
