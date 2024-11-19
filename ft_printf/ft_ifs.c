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

int	if_c(va_list args)
{
	int	cntr;
	int	ret;

	cntr = 0;
	ret = 0;
	ret = ft_putchar(va_arg(args, int));
	if (ret == -1)
		return (-1);
	cntr += ret;
	return (cntr);
}

int	ft_ifs(char c, va_list args)
{
	int	cntr;

	cntr = 0;
	if (c == 'c')
		cntr += if_c(args);
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
		ft_putstr("0x");
		cntr += (ft_puthexptr((uintptr_t)va_arg(args, void *)));
		if (cntr > 0)
			cntr += 2;
	}
	else if (c == '%')
		cntr += ft_putchar('%');
	return (cntr);
}
