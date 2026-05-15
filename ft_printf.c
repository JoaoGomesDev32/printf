/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:25:32 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/15 16:27:26 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
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