/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:34:17 by nchebbi           #+#    #+#             */
/*   Updated: 2022/12/16 17:10:23 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

int	main(void)
{
	ft_printf("(null) %s NULL ", NULL);
	ft_printf("voici un char %c\n", 'B');
	ft_printf("voici deux nombre entier : %d, %i\n", 12345, -9846537);
	ft_printf("\001\002\007\v\010\f\r\n");
	return (0);
}
