/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:52:00 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/26 14:18:39 by tbordian         ###   ########.fr       */
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
	{
		if (write(1, NULL_STRING, 3) == -1)
			return (-1);
		return (3);
	}
	count += ft_putstr("0x");
	if (count == -1)
		return (-1);
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
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	if (c == 'p')
		return (convert_pointer(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		count;
	int		prot;

	count = 0;
	va_start(args, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			prot = format_specifier(f, 0, args);
			if (prot == -1)
				return (-1);
		}
		else if (write(1, f, 1) == -1)
			return (-1);
		else
			prot = 1;
		count += prot;
		f++;
	}
	va_end(args);
	return (count);
}
