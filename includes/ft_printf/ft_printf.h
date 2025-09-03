/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:42:58 by lbento            #+#    #+#             */
/*   Updated: 2025/08/05 13:32:54 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_printf(char c);
int		ft_putnbr_printf(int nbr);
int		ft_pointerhex(void *ptr);
int		ft_putstr_printf(char *str);
int		ft_putnbr_u(unsigned int nbr);
char	*ft_strchr(const char *s, int c);
int		ft_putnbr_hex(unsigned int nbr, int l_case);
int		ft_printf(const char *format, ...);

#endif
