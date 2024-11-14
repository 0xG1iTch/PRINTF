/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 09:08:03 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-13 09:08:03 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		cntr;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	cntr = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX\%", str[i + 1]))
		{
			cntr += ft_ifs(str[++i], args);
			i++;
		}
		else
			cntr += ft_putchar(str[i++]);
	}
	va_end(args);
	return (cntr);
}
