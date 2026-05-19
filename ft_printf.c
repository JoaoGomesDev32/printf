/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:25:32 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/19 17:58:45 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt)
				count += ft_format(args, *fmt);
		}
		else
			count += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int	a;
	int	b;

	printf("=== %%d basico ===\n");
	a = ft_printf("Hello %d\n", 42);
	b = printf("Hello %d\n", 42);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== INT_MIN ===\n");
	a = ft_printf("%d\n", INT_MIN);
	b = printf("%d\n", INT_MIN);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== INT_MAX ===\n");
	a = ft_printf("%d\n", INT_MAX);
	b = printf("%d\n", INT_MAX);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== zero decimal ===\n");
	a = ft_printf("%d\n", 0);
	b = printf("%d\n", 0);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%u maximo ===\n");
	a = ft_printf("%u\n", 4294967295U);
	b = printf("%u\n", 4294967295U);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%u zero ===\n");
	a = ft_printf("%u\n", 0);
	b = printf("%u\n", 0);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%x lowercase ===\n");
	a = ft_printf("%x\n", 42);
	b = printf("%x\n", 42);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%X uppercase ===\n");
	a = ft_printf("%X\n", 42);
	b = printf("%X\n", 42);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%x zero ===\n");
	a = ft_printf("%x\n", 0);
	b = printf("%x\n", 0);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%c normal ===\n");
	a = ft_printf("%c\n", 'A');
	b = printf("%c\n", 'A');
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%c nulo ===\n");
	a = ft_printf("%c\n", 0);
	b = printf("%c\n", 0);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%s normal ===\n");
	a = ft_printf("%s\n", "hello");
	b = printf("%s\n", "hello");
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%s vazia ===\n");
	a = ft_printf("%s\n", "");
	b = printf("%s\n", "");
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%s NULL ===\n");
	a = ft_printf("%s\n", (char *)NULL);
	printf("ft:%d\n\n", a);

	printf("=== %%p valido ===\n");
	int x = 42;
	a = ft_printf("%p\n", &x);
	b = printf("%p\n", &x);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%p NULL ===\n");
	a = ft_printf("%p\n", NULL);
	b = printf("%p\n", NULL);
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== %%%% ===\n");
	a = ft_printf("%%\n");
	b = printf("%%\n");
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== 100%%%% ===\n");
	a = ft_printf("100%%\n");
	b = printf("100%%\n");
	printf("ft:%d | printf:%d\n\n", a, b);

	printf("=== combinado ===\n");
	a = ft_printf("%d %s %x %X %p %%\n", 42, "hello", 42, 42, &x);
	b = printf("%d %s %x %X %p %%\n", 42, "hello", 42, 42, &x);
	printf("ft:%d | printf:%d\n\n", a, b);

	return (0);
}
*/