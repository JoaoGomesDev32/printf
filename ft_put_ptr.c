/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:06:12 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/19 17:07:33 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putptr_hex(address);
	return (count);
}
