/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:46:43 by nchebbi           #+#    #+#             */
/*   Updated: 2022/12/19 14:32:25 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//n = nombre a passer en hexa 
// base = base de traduction pour passer dun int a un hexadecimal
// size = taille de la base voulu.
// i = iterateur

static int	putnbr_base(unsigned long long n, char *base,
							unsigned long long size, int i)
{
	unsigned long long	nb;

	nb = n;
	if (n >= size)
		i = putnbr_base(n / size, base, size, i);
	i += ft_putchar(base[nb % size]);
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char *base, int nb)
{
	if (n < 0)
		return (putnbr_base(n * -1, base, nb, 0) + 1);
	return (putnbr_base(n, base, nb, 0));
}

// int	ft_hex_len(unsigned int num)
// {
// 	int	len;

// 	len = 0;
// 	while (num != 0)
// 	{
// 		len++;
// 		num = num / 16;
// 	}
// 	return (len);
// }

// char	*ft_int_to_hex(unsigned int num)
// {
// 	char	digit[100];
// 	int		rest;
// 	int		i;
// 	char	j;
// 	char	*res;

// 	i = 0;
// 	while (num > 0)
// 	{
// 		189 / 16 = 11 et quelque
// 			11 = b dans la string
// 		189 % 16= 13
// 		si 13 plus grand que 16 recommencer sinon le rentrer dans la string
// 			13 = D

//		if (num / 16 < 16)
//			num / 16 = j
//
		//https://www.sanfoundry.com/c-program-convert-decimal-hex/
		//site montrant une version identique a la mienne.
// 		rest = num % 16;
// 		if (rest < 10)
// 			reversed_digit[i] = '0' + rest;
// 		else
// 			reversed_digit[i] = 'a' + (rest - 10);
// 		num = num / 16;
// 		i++;
// 	}
// 	res = (char *)malloc(sizeof(char) * i);
// 	i--;
// 	while (i != 0)
// 		res[j++] = reversed_digit[i--];
// 	return (res);
// }

// char	*ft_int_to_hexcaps(unsigned int num)
// {
// 	char	reversed_digit[100];
// 	int		rest;
// 	int		i;
// 	int		j;
// 	char	*res;

// 	i = 0;
// 	j = 0;
// 	while (num > 0)
// 	{
// 		rest = num % 16;
// 		if (rest < 10)
// 			reversed_digit[i] = '0' + rest;
// 		else if (num < 16 && num >= 10)
// 			reversed_digit[i] = 'A' + (rest - 10);
// 		num = num / 16;
// 		i++;
// 	}
// 	*res = (int)malloc(sizeof (int) * i);
// 	i--;
// 	while (i != -1)
// 		res[j++] = reversed_digit[i--];
// 	return (res);
// }

// int	ft_printf_hexa(unsigned int num, const char format)
// {
// 	(void) num;
// 	(void) format;
// 	// if (format == 'x')
// 	// 	return (ft_printf_str(ft_int_to_hex(num)));
// 	// else if (format == 'X')
// 	// 	return (ft_printf_str(ft_int_to_hexcaps(num)));
// 	// else
// 		return (0);
// }
