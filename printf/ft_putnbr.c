/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:46:45 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/23 14:59:38 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	edge_case(int n)
{
	int	prot;

	if (n == -2147483648)
	{
		prot = write(1, "-2147483648", 11);
		if (prot == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr(int n)
{
	char	digit;
	int		count;
	int		prot;

	count = 0;
	prot = 0;
	if (n == -2147483648)
		return(edge_case(n));
	if (n < 0)
	{
		prot = write(1, "-", 1);
		if (prot == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	digit = '0' + (n % 10);
	prot = write(1, &digit, 1);
	if (prot == -1)
		return (-1);
	return (count + 1);
}
