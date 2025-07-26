/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:44:22 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/24 21:30:56 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//"(null) problem"
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
