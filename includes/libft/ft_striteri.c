/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:25:59 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:58:52 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
	i++;
	}
}
// static void	upper_level(unsigned int i, char *s)
// {
// 	if (i % 2 == 0)
// 	{
// 		*s = ft_toupper(*s);
// 	}
// }
// #include <stdio.h>
// int	main(void)
// {
// 	char s[] = "\0";
// 	ft_striteri(s, upper_level);
// 	printf("%s\n", s);
// }
