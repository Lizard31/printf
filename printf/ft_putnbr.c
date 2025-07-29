/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:46:45 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/29 13:31:43 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	edge_case(int n)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr(int n)
{
	char	digit;
	int		count;
	int		temp;

	count = 0;
	if (n == -2147483648)
		return (edge_case(n));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		temp = ft_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	digit = '0' + (n % 10);
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[count])
	{
		if (write(1, &str[count], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}
