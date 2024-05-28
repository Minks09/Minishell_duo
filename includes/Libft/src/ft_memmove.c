/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:52:58 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/23 23:01:07 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*source;

	if (&dst[0] < &src[0])
		return (ft_memcpy(dst, src, len));
	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (len > 0)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
	return (dst);
}
