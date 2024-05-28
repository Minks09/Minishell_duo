/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_entier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:02:18 by nchebbi           #+#    #+#             */
/*   Updated: 2022/12/19 14:44:37 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str);

int	ft_printf_nbr(int num)
{
	int		len;
	char	*numchar;

	len = 0;
	numchar = ft_itoa(num);
	len = ft_printf_str(numchar);
	free(numchar);
	return (len);
}
