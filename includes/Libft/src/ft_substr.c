/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:13 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/23 23:03:12 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	slen -= start;
	if (len < slen)
		slen = len;
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s + start, slen);
	str[slen] = '\0';
	return (str);
}
