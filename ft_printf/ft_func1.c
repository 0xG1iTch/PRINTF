/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 09:07:58 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-13 09:07:58 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	cntr;
	int	ret;

	i = 0;
	cntr = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ret = ft_putchar(str[i++]);
		if (ret == -1)
			return (-1);
		cntr += ret;
	}
	return (cntr);
}

int	ft_puthex(unsigned int nb, char c)
{
	char	*hex;
	int		i;
	int		ret;

	i = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
		i += ft_puthex(nb / 16, c);
	ret = ft_putchar(hex[nb % 16]);
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}

int	ft_puthexptr(uintptr_t nb)
{
	char	*hex ;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
		i += ft_puthexptr(nb / 16);
	i += ft_putchar(hex[nb % 16]);
	i = fail_check(i);
	return (i);
}
