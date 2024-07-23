/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:08:11 by nchebbi           #+#    #+#             */
/*   Updated: 2024/07/05 01:14:25 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strndup_GNL(char *str, int size)
{
	char	*ret;

	ret = (char *)malloc((size + 1) * sizeof(char));
	ret[size] = '\0';
	if (!ret)
		return (NULL);
	if (!str)
	{
		ret[0] = '\0';
		return (ret);
	}
	while (--size >= 0)
	{
		ret[size] = str[size];
	}
	return (ret);
}

int	ft_strchr_i(const char *s, int c)
{
	size_t		len;
	size_t		i;

	i = 0;
	if (!s)
		return (-1);
	len = ft_strlen_GNL(s);
	while (s[i] != '\0' && s[i] != (unsigned char)c && i < len)
	{
		i++;
	}
	if (s[i] == (unsigned char)c && i <= len)
		return (i);
	return (-1);
}

char	*ft_strjoin_GNL(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = -1;
	len = ft_strlen_GNL(s1) + ft_strlen_GNL(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen_GNL(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_calloc_GNL(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
