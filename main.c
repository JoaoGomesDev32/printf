/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:17:22 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/15 17:38:59 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int a;
	int b;

	a = ft_printf("Hello %d\n", 42);
	b = printf("Hello %d\n", 42);

	printf("ft_printf: %d\n", a);
	printf("printf: %d\n", b);
	
	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	ft_printf("%X\n", 42);
	printf("%X\n", 42);

	ft_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);

	ft_printf("%u\n", 4294967295U);
	printf("%u\n", 4294967295U);

	ft_printf("%s\n", (char *)NULL);
	printf("%s\n", (char *)NULL);

	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);

	ft_printf("%x\n", 0);
	printf("%x\n", 0);

	ft_printf("%X\n", 0);
	printf("%X\n", 0);

	ft_printf("%u\n", 0);
	printf("%u\n", 0);

	ft_printf("%d\n", 0);
	printf("%d\n", 0);

	ft_printf("%%\n");
	printf("%%\n");

	ft_printf("%d %s %x %X %p %%\n",
		42,
		"hello",
		42,
		42,
		"test");

	printf("%d %s %x %X %p %%\n",
		42,
		"hello",
		42,
		42,
		"test");

	return (0);
}