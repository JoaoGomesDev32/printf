/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:05:32 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/15 16:21:08 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char spec)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (spec == '%')
		return (ft_putchar('%'));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (spec == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (0);
}