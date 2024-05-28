/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:10:20 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/23 23:00:54 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 >= 1 || n / 10 <= -1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		offset;

	offset = 0;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		str[--len] = -(n % 10) + '0';
		n = (n / 10) * -1;
		offset = 1;
	}
	while (--len >= offset)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
