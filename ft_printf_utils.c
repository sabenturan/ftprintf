/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturan <mturan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:19:38 by mturan            #+#    #+#             */
/*   Updated: 2023/07/27 16:22:41 by mturan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		ret++;
		if (ft_putchar(*str) == -1)
			return (-1);
		str++;
	}
	return (ret);
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (sign == 1)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		ret = 2;
		sign = 0;
	}
	if (a >= 16)
	{
		tmp = ft_point(a / 16, sign);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (++ret);
}

int	ft_putnbr(int n)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret++;
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (++ret);
}

int	ft_unsigned(unsigned int a)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (a >= 10)
	{
		tmp = ft_unsigned(a / 10);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (ft_putchar(a % 10 + '0') == -1)
		return (-1);
	return (++ret);
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (a >= 16)
	{
		tmp = ft_hex(a / 16, c);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[a % 16], 1) == -1)
			return (-1);
	}
	return (++ret);
}
