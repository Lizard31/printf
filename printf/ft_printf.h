/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:52:07 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/23 16:10:00 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

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
