/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:41:59 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/26 13:41:59 by tbordian         ###   ########.fr       */
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
	int		count;
	int		temp;
	char	digit;

	count = 0;
	if (n >= 10)
	{
		temp = ft_putnbr_unsigned(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	digit = '0' + n % 10;
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}

static char	digit_to_hex(int digit, int uppercase)
{
	if (digit < 10)
		return ('0' + digit);
	else if (uppercase)
		return ('A' + digit - 10);
	else
		return ('a' + digit - 10);
}

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	int		count;
	int		temp;
	char	hex_char;

	count = 0;
	if (n >= 16)
	{
		temp = ft_putnbr_hex(n / 16, uppercase);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	hex_char = digit_to_hex(n % 16, uppercase);
	if (write(1, &hex_char, 1) == -1)
		return (-1);
	return (count + 1);
}
