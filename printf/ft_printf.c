/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:52:00 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/23 14:42:09 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_putnbr_hex(addr, 0);
	return (count);
}

static int	format_specifier(const char *f, int i, va_list args)
{
	char	c;

	c = f[i];
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (convert_pointer(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

// print loop inside the ptintf
int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		char_count;
	int		position_tracker;

	va_start(args, f);
	char_count = 0;
	position_tracker = 0;
	while (f[position_tracker] != '\0')
	{
		if (f[position_tracker] == '%')
		{
			position_tracker++;
			char_count += format_specifier(f, position_tracker, args);
			position_tracker++;
		}
		else
		{
			write(1, &f[position_tracker], 1);
			char_count++;
			position_tracker++;
		}
	}
	va_end(args);
	return (char_count);
}
