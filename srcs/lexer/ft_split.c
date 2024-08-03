/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:41:30 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/03 15:22:45 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	count_strings(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], sep) == 1)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && check_sep(str[i], sep) == 0)
			i++;
	}
	return (count);
}

int	size_of_strings(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && check_sep(str[i], sep) == 0)
		i++;
	return (i);
}

char	*ft_stringdup(const char *str, char sep)
{
	int		i;
	int		len_str;
	char	*string;

	i = 0;
	len_str = size_of_strings(str, sep);
	string = (char *)malloc(sizeof(char) * len_str + 1);
	if (string == NULL)
		return (NULL);
	while (i < len_str)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split_parse(const char *str, char sep)
{
	int		i;
	int		nbr_of_strs;
	char	**strings;

	i = 0;
	nbr_of_strs = count_strings(str, sep);
	strings = (char **)malloc(sizeof(char *) * (nbr_of_strs + 1));
	if (strings == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (check_sep(*str, sep) == 1))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_stringdup(str, sep);
			i++;
		}
		while (*str != '\0' && (check_sep(*str, sep) == 0))
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
/*
int	main(int argc, char **argv)
{
	int		i;
	char	sep;
	char	**strs;

	(void)argc;
	i = 0;
	sep = ' ';
	strs = ft_split(argv[1], sep);
	while (strs[i] != 0)
	{
		printf("%s\n", strs[i]);
		i++;
	}
	return (0);
}
*/