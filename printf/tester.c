/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbordian <tbordian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:28 by tbordian          #+#    #+#             */
/*   Updated: 2025/07/24 21:30:17 by tbordian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// int	main(void)
// {
// 	int		ret1, ret2;
// 	char	*str = "Hello, 42!";
// 	char	*nullstr = NULL;
// 	int		n = -42;
// 	unsigned int u = 4294967295U;
// 	void	*ptr = str;
// 	void	*null_ptr = NULL;

// 	printf("==== ft_printf vs printf tester ====\n\n");
// 	// %s
// 	ret1 = ft_printf("ft_printf: s: %s\n", str);
// 	ret2 = printf("printf   : s: %s\n", str);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
// 	// %s with NULL
// 	ret1 = ft_printf("ft_printf: null string: %s\n", nullstr);
// 	ret2 = printf("printf   : null string: %s\n", nullstr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %p
// 	ret1 = ft_printf("ft_printf: p: %p\n", ptr);
// 	ret2 = printf("printf   : p: %p\n", ptr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %p with NULL
// 	ret1 = ft_printf("ft_printf: null pointer: %p\n", null_ptr);
// 	ret2 = printf("printf   : null pointer: %p\n", null_ptr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
// }
