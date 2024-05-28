/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:26:11 by nchebbi           #+#    #+#             */
/*   Updated: 2022/12/17 18:28:57 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include "../../libft.h"

int			ft_printf(const char *s, ...);
int			ft_putstr(char *str);
int			ft_printf_str(char *str);
int			ft_printf_nbr(int n);
int			ft_printpercent(void);
int			ft_num_len(unsigned int num);
char		*ft_uitoa(unsigned int n);
int			ft_printf_unsignedint(unsigned int n);
int			ft_putchar_one(char c);
int			ft_printf_nbr(int num);
int			ft_putnbr_base(unsigned long long n, char *base, int nb);
int			ft_putchar(char c);

#endif