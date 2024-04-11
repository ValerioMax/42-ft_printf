/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdessena <vdessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:02:55 by valerio           #+#    #+#             */
/*   Updated: 2024/04/11 20:35:51 by vdessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign(unsigned long n, char *buf, const char *base)
{
	if (n == 0)
		*buf = '\0';
	else
	{
		*buf = base[(n % 16)];
		assign(n / 16, buf + 1, base);
	}
}

char	*to_hexa1(unsigned int n, char *buf, const char *base)
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
	assign(n, buf, base);
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

char	*to_hexa2(unsigned long n, char *buf, const char *base)
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
	assign(n, buf, base);
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

int	put_pointer(long mem, const char *base)
{
	char	*buf;
	int		count;

	count = 0;
	if (mem == 0)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		buf = malloc(17);
		if (!buf)
			return (0);
		buf = to_hexa2(mem, buf, base);
		count += ft_putstr_fd("0x", 1) + ft_putstr_fd(buf, 1);
		free(buf);
	}
	return (count);
}

int	put_hexa(unsigned int mem, const char *base)
{
	char	*buf;
	int		count;

	count = 0;
	buf = malloc(9);
	if (!buf)
		return (0);
	buf = to_hexa1(mem, buf, base);
	count += ft_putstr_fd(buf, 1);
	free(buf);
	return (count);
}
