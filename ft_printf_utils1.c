/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:46 by valerio           #+#    #+#             */
/*   Updated: 2024/04/02 14:55:39 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_pow(int base, int exp)
{
	long	res;

	res = 1;
	while (exp > 0)
	{
		res *= base;
		exp--;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

long	ft_putnbr_fd(char c, long n, int fd)
{
	if (n < 0)
	{
		if (c == 'u')
			return (ft_putnbr_fd(c, n + ft_pow(2, 32), fd));
		else
			return (ft_putchar_fd('-', fd) + ft_putnbr_fd(c, -n, fd));
	}
	else if (n >= 10)
		return (ft_putnbr_fd(c, n / 10, fd) + ft_putchar_fd(n % 10 + '0', fd));
	else
		return (ft_putchar_fd(n + '0', fd));
}
