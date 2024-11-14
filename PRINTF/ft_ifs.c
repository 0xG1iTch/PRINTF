/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 09:16:38 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-13 09:16:38 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ifs(char c, va_list args)
{
	int			cntr;
	uintptr_t	nb;

	cntr = 0;
	if (c == 'c')
		cntr += ft_putchar(va_arg(args, int));
	else if (c == 's')
		cntr += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		cntr += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		cntr += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		cntr += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
	{
		nb = (uintptr_t)va_arg(args, void *);
		if (nb == 0)
			return (cntr += ft_putstr("(nil)"));
		ft_putstr("0x");
		cntr += (2 + ft_puthexptr(nb));
	}
	else if (c == '%')
		cntr += ft_putchar('%');
	return (cntr);
}
