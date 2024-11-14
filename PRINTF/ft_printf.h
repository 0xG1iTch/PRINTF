/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 08:49:33 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-13 08:49:33 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

char	*ft_strchr(const char *s, int c);

int		ft_puthex(unsigned int nb, char c);
int		ft_printf(const char *str, ...);
int		ft_put_unsigned(unsigned int n);
int		ft_ifs(char c, va_list args);
int		ft_puthexptr(uintptr_t nb);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
#endif