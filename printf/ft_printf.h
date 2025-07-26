/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:52:07 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/26 14:25:21 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined(__linux__)
#  define NULL_STRING "(nil)"
#  define NULL_STRING_LENGTH 5
# elif defined(__APPLE__)
#  define NULL_STRING "0x0"
#  define NULL_STRING_LENGTH 3
# endif

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);

int		ft_putnbr_hex(unsigned long n, int uppercase);
int		ft_printf(const char *f, ...);
int		count_digits(int n);
int		count_digits_unsigned(unsigned int n);
int		ft_putnbr_unsigned(unsigned int n);

#endif
