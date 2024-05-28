/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:48:40 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/25 18:13:18 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_sortparam(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar_one(va_arg(arg, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putstr("0x")
			+ ft_putnbr_base(va_arg(arg, unsigned long long),
				"0123456789abcdef", 16));
	if (c == 'i' || c == 'd')
		return (ft_printf_nbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_printf_unsignedint(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789abcdef", 16));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789ABCDEF", 16));
	if (c == '%')
		return (ft_putchar_one('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t		nbr_writtenchar;
	va_list		arg;

	va_start (arg, s);
	nbr_writtenchar = 0;
	while (*s != '\0')
	{
		if (*s != '%')
			nbr_writtenchar += ft_putchar_one(*s);
		else if (*s == '%')
		{
			s++;
			nbr_writtenchar += ft_sortparam(*s, arg);
		}
		s++;
	}
	va_end(arg);
	return (nbr_writtenchar);
}
