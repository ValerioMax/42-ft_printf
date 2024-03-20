/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:59:53 by valerio           #+#    #+#             */
/*   Updated: 2024/03/20 13:46:08 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //provv
#include <math.h> //provv

int ft_printf(const char *s, ...) // devo mettere const char *nomeParametro oppure lasciare const char * ?
{
	char	*buf;
	long	mem;

	va_list args;
	int		i;
	int		count; //va bene int?
	
	count = 0;
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == '%' || s[i] == 'c')
				count += ft_putchar_fd(va_arg(args, int), 1); //char?
			else if (s[i] == 's')
				count += ft_putstr_fd(va_arg(args, void *), 1);
			else if (s[i] == 'p')
			{
				mem = (long) va_arg(args, void *);
				if (mem == 0)
				{
					write(1, "(nil)", 5);
					count += 5;
				}
				else
				{
					buf = malloc(18);
					write(1, "0x", 2);
					buf = to_hexa(mem, buf, "0123456789abcdef");
					count += ft_putstr_fd(buf, 1);
					count += 2;
					free(buf);
				}
			}
			else if (s[i] == 'd' || s[i] == 'i')
				count += ft_putnbr_fd(va_arg(args, int), 1);
			else if (s[i] == 'u')
			{
				mem = va_arg(args, long);
				if (mem < 0)
				{
					mem += pow(2, 32) - 1;
				}
				count += ft_putnbr_fd(mem, 1);
			}
			else if (s[i] == 'x')
			{
				buf = malloc(18); //'\0' più '-' in caso sia negativo il numero
				buf = to_hexa(va_arg(args, long), buf, "0123456789abcdef");
				count += ft_putstr_fd(buf, 1);
				free(buf);
			}
			else if (s[i] == 'X')
			{
				buf = malloc(18); //'\0' più '-' in caso sia negativo il numero
				buf = to_hexa(va_arg(args, long), buf, "0123456789ABCDEF");
				count += ft_putstr_fd(buf, 1);
				free(buf);
			}
		}
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







