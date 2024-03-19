/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:59:53 by valerio           #+#    #+#             */
/*   Updated: 2024/03/19 14:48:55 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h> //provv
#include <stdio.h> //provv

static void assign(long int n, char *buf, int i, char *base)
{
	if (n < 0)
		assign(-n, buf, 1, base);
	else if (n == 0)
	{
		if (i == 1)
			*buf++ = '-';
		*buf = '\0';
	}
	else
	{
		assign(n / 16, buf + 1, i, base);
		*buf = base[(n % 16)];
	}
}

char	*to_hexa(long int n, char *buf, char *base)
{
	int		i;
	int		len;
	char	temp;

	assign(n, buf, 0, base);
	i = 0;
	len = strlen(buf);
	while (i < len / 2)
	{
		temp = buf[i];
		buf[i] = buf[len - 1 - i];
		buf[len - 1 - i] = temp;
		i++;
	}
	return (buf);
}

int ft_printf(const char *s, ...) // devo mettere const char *nomeParametro oppure lasciare const char * ?
{
	char	*buf;
	long	mem;

	va_list args;
	int		i;
	
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == '%' || s[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1); //char?
			else if (s[i] == 's')
				ft_putstr_fd(va_arg(args, void *), 1);
			else if (s[i] == 'p')
			{
				mem = (long) va_arg(args, void *);
				buf = malloc(17);
				write(1, "0x", 2);
				buf = to_hexa(mem, buf, "0123456789abcdef");
				ft_putstr_fd(buf, 1);
				free(buf);
			}
			else if (s[i] == 'd' || s[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			//else if (s[i] == 'u')
			else if (s[i] == 'x')
			{
				buf = malloc(18); //'\0' più '-' in caso sia negativo il numero
				buf = to_hexa(va_arg(args, int), buf, "0123456789abcdef");
				ft_putstr_fd(buf, 1);
				free(buf);
			}
			else if (s[i] == 'X')
			{
				buf = malloc(18); //'\0' più '-' in caso sia negativo il numero
				buf = to_hexa(va_arg(args, int), buf, "0123456789ABCDEF");
				ft_putstr_fd(buf, 1);
				free(buf);
			}
		}
		else
			ft_putchar_fd(s[i], 1);		
		i++;
	}
	va_end(args);
	return (i-1); //?
}




