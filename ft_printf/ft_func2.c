/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 13:49:31 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-13 13:49:31 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	fail_check(int i)
{
	if (i < 0)
		return (-1);
	return (i);
}

int	ft_put_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_put_unsigned(n / 10);
		i += ft_put_unsigned(n % 10);
	}
	else
		i += ft_putchar (n + 48);
	i = fail_check(i);
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		i += ft_putstr("-2147483648");
	else if (nb < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	i = fail_check(i);
	return (i);
}
