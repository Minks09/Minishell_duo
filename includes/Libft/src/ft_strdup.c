/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:37:46 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/23 23:02:10 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = (int)ft_strlen(s1);
	if (s1[len] == '\0')
		len++;
	s2 = (char *)malloc(len * sizeof(char));
	if (!s2)
	{
		free(s2);
		return (NULL);
	}
	while (--len >= 0)
	{
		s2[len] = s1[len];
	}
	return (s2);
}
