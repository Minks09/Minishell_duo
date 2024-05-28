/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:07:54 by nchebbi           #+#    #+#             */
/*   Updated: 2022/12/15 16:50:35 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	i;

	if (str == NULL)
		str = "(null)";
	i = -1;
	while (str[++i])
		ft_putchar_one(str[i]);
	return (i);
}
