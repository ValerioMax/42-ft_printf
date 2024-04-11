/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdessena <vdessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:59:53 by valerio           #+#    #+#             */
/*   Updated: 2024/04/11 20:36:14 by vdessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(*args, void *), 1);
	else if (c == 'p')
		count += put_pointer((long) va_arg(*args, void *), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(c, va_arg(*args, int), 1);
	else if (c == 'u')
		count += ft_putnbr_fd(c, va_arg(*args, int), 1); //se gli avessi passato long faceva in automatico il casting a unsigned e non c'era bisogno di if(c=='u') in ft_putnbr(non ho capito perché)
	else if (c == 'x')
		count += put_hexa(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += put_hexa(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	else
		count += ft_putchar_fd(c, 1);
	return (count);
}

int	ft_printf(const char *s, ...) // devo mettere const char *nomeParametro oppure lasciare const char * ?
{
	va_list	args;
	int		count;
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
	return (count);
}

/*
#include <limits.h>
int main()
{
	
	printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//return (0);
	
	

	printf(" %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p \n\n", LONG_MIN, LONG_MAX);
	printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	
	return 0;
}
*/
