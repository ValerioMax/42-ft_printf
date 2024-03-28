/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:01:27 by valerio           #+#    #+#             */
/*   Updated: 2024/03/28 17:12:05 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTH_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *s, ...);

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
long	ft_putnbr_fd(long n, int fd);
char	*ft_strdup(const char *s);
char	*to_hexa(unsigned long int n, char *buf, char *base);

#endif