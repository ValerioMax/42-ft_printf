/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:46 by valerio           #+#    #+#             */
/*   Updated: 2024/03/28 17:19:43 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
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

long	ft_putnbr_fd(long n, int fd)
{
	/*if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else*/ if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-n, fd));
	else if (n >= 10)
		return (ft_putnbr_fd(n / 10, fd) + ft_putchar_fd(n % 10 + '0', fd));
	else
		return (ft_putchar_fd(n + '0', fd));
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || (!dest && !src) || n == 0)
		return (dest);
	while (n--)
		((char *) dest)[n] = ((char *) src)[n];
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*pt;
	size_t	len;

	len = ft_strlen(s);
	pt = (char *) malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	pt = ft_memcpy(pt, s, len + 1);
	return (pt);
}

static void assign(unsigned long int n, char *buf, int i, char *base)
{
	/*if (n < 0)
		assign(-n, buf, 1, base);
	else*/ if (n == 0)
	{
		if (i == 1)
			*buf++ = '-';
		*buf = '\0';
	}
	else
	{
		//printf("%lld, %lld, %lld, %c\n", n, n/16, n%16, base[(n % 16)]);
		*buf = base[(n % 16)];
		assign(n / 16, buf + 1, i, base);
	}
}

char	*to_hexa(unsigned long int n, char *buf, char *base)
{
	int		i;
	int		len;
	char	temp;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (buf);
	}
	assign(n, buf, 0, base);
	i = 0;
	len = ft_strlen(buf);
	while (i < len / 2)
	{
		temp = buf[i];
		buf[i] = buf[len - 1 - i];
		buf[len - 1 - i] = temp;
		i++;
	}
	return (buf);
}
