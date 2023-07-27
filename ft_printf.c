/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturan <mturan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:29:01 by mturan            #+#    #+#             */
/*   Updated: 2023/07/27 16:17:49 by mturan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_format(va_list *args, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg((*args), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((*args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else if (c == 's')
		return (ft_putstr(va_arg((*args), char *)));
	else
		return (ft_putstr("%"));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;
	int		tmp;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			tmp = ft_format(&args, str[i]);
			if (tmp == -1)
				return (-1);
			ret += tmp - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
		ret++;
	}
	va_end(args);
	return (ret);
}
