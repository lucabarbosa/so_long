/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:09:06 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:53:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pasted;
	const unsigned char	*copied;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	copied = (const unsigned char *)src;
	pasted = (unsigned char *)dest;
	if (pasted > copied)
		while (n-- > 0)
			pasted[n] = copied [n];
	else
	{
		i = 0;
		while (i < n)
		{
			pasted[i] = copied[i];
			i++;
		}
	}
	return (dest);
}
// #include <stdio.h>
// int 	main(void)
// {
// 	char str[11] = "ABCDEFGHIJ";
// //    int src[3] = {1, 2, 3};
// //    int dst[3];

// //	ft_memmove(dst, src, sizeof(str));
// //    printf("dst = [%d, %d, %d]\n\n\n", dst[0], dst[1], dst[2]);

// 	ft_memmove(str+3, str, 8);
//     printf("%s\n\n\n", str);

// //    ft_memmove(str, "Test", 5);
// //    printf("%s\n", str);
// 	return (0);
// }
