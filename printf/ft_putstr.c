/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:44:22 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/23 14:36:38 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	prot;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		prot = write(1, &str[count], 1);
		if (prot == -1)
			return (-1);
		count++;
	}
	return (count);
}
