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

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        size_t  i;

        if (!dest && !src)
                return (NULL);
        if (dest == src)
                return (dest);
        i = 0;
        if (dest > src)
        {
                while (i < n)
                {
                        ((char *)dest)[n - 1] = ((char *)src)[n - 1];
                        n--;
                }
        }
        else
        {
                while (i < n)
                {
                        ((char *)dest)[i] = ((char *)src)[i];
                        i++;
                }
        }
        return (dest);
}
