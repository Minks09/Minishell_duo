/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:42:18 by nchebbi           #+#    #+#             */
/*   Updated: 2024/05/23 23:02:05 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_strs(char const *s, char c)
{
	int		nb;

	nb = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		nb++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nb);
}

static int	ft_strlen_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
	free(result);
}

static void	ft_free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i++] != NULL)
	{
		free(s[i]);
	}
	free(s[i]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	i;

	count = ft_count_strs(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_strndup(s, ft_strlen_c(s, c));
		if (result == NULL)
		{
			ft_free_arr(result);
			return (0);
		}
		s += ft_strlen_c(s, c);
		i++;
	}
	result[count] = 0;
	return (result);
}
