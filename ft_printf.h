/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturan <mturan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:29:04 by mturan            #+#    #+#             */
/*   Updated: 2023/07/27 16:39:30 by mturan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list *args, char c);
int		ft_putnbr(int n);
int		ft_hex(unsigned int a, char c);
int		ft_point(unsigned long a, int sign);
int		ft_putstr(char *str);
int		ft_unsigned(unsigned int a);
int		ft_putchar(char c);

#endif
