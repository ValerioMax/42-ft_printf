/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:59:53 by valerio           #+#    #+#             */
/*   Updated: 2024/04/02 13:19:42 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //provv
#include <math.h> //provv

static int	put_pointer(long mem, const char *base)
{
	char	*buf;
	int		count;

	count = 0;
	if (mem == 0)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		buf = malloc(18);
		buf = to_hexa(mem, buf,	base);
		count += ft_putstr_fd("0x", 1) + ft_putstr_fd(buf, 1);
		free(buf);
	}
	return (count);
}

static int	put_hexa(long mem, const char *base)
{
	char	*buf;
	int		count;

	count = 0;
	buf = malloc(18); //'\0' più '-' in caso sia negativo il numero
	buf = to_hexa(mem, buf, base);
	count += ft_putstr_fd(buf, 1);
	free(buf);
	return (count);
}

static int	aux(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(*args, int), 1); //char?
	else if (c == 's')
		count += ft_putstr_fd(va_arg(*args, void *), 1);
	else if (c == 'p')
		count += put_pointer((long) va_arg(*args, void *), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(c, va_arg(*args, int), 1);
	else if (c == 'u')
		count += ft_putnbr_fd(c, va_arg(*args, long), 1);
	else if (c == 'x')
		count += put_hexa(va_arg(*args, long), "0123456789abcdef");
	else if (c == 'X')
		count += put_hexa(va_arg(*args, long), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	else
		count += ft_putchar_fd(c, 1);
	return (count);
}



int ft_printf(const char *s, ...) // devo mettere const char *nomeParametro oppure lasciare const char * ?
{
	va_list args;
	int		count; //va bene int?
	int		i;
	
	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count += aux(&args, s[++i]);
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (count); //?
}

/*
int main()
{
	return (0);
}
*/







