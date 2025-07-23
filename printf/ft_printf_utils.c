/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:41:59 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/23 15:09:10 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count = 1;
		if (n == -2147483648)
			return (11);
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	count_digits_unsigned(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count = 0;

	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar('0' + n % 10);

	return (count);
}

static char	digit_to_hex(int digit, char *uppercase)
{
	if (digit < 10)
		return ('0' + digit);
	else if (uppercase)
		return ('A' + digit - 10);
	else
		return ('a' + digit - 10);
}

int	ft_putnbr_hex(unsigned long n, char *uppercase)
{
	int		count;
	char	hex_char;
	int		prot;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	hex_char = digit_to_hex(n % 16, uppercase);
	prot = write(1, &hex_char, 1);
	if (prot == -1)
		return (-1);
	return (count + 1);
}
