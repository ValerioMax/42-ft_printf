/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:57:44 by valerio           #+#    #+#             */
/*   Updated: 2024/04/02 14:58:28 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
long	ft_putnbr_fd(char c, long n, int fd);
char	*to_hexa(unsigned long int n, char *buf, const char *base);
int		put_pointer(long mem, const char *base);
int		put_hexa(long mem, const char *base);

#endif