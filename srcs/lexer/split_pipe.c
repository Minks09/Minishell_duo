/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:32:09 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/02 17:16:01 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_strings_pipe(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (strncmp(str, "|\0", 2) == 0)
		return (1);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], sep) == 1)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && check_sep(str[i], sep) == 0)
			i++;
	}
    count += count - 1;
	return (count);
}

char	**ft_split_pipe(const char *str, char sep)
{
	int		i;
	int		nbr_of_strs;
	char	**strings;

	i = 0;
	nbr_of_strs = count_strings_pipe(str, sep);
	strings = (char **)malloc(sizeof(char *) * (nbr_of_strs + 1));
	if (strings == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (check_sep(*str, sep) == 1))
			str++;
		if (*str != '\0')
		{
			strings[i++] = ft_stringdup(str, sep);
            if (i < nbr_of_strs)
                strings[i++] = ft_strdup("|");
		}
		while (*str != '\0' && (check_sep(*str, sep) == 0))
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
char    **split_pipe(char **str)
{
    int i;
    int size;
    char **tab;

    i = 0;
    size = 0;
    while (str[i] != NULL)
        size += count_strings_pipe(str[i++], '|');
    tab = malloc(sizeof(char *) * (size + 1));
    if (!tab)
        return (NULL);
    i = 0;
    while (str[i] != NULL)
        i++;
    fill_new_tab(str, tab, i);
    free_tab(str);
    return(tab);
}
void    fill_new_tab(char **str,char **tab, int size)
{
    int i;
    int j;
    int z;
    char **tmp;
    
    i = 0;
    z = 0;
    while (i < size)
    {
        if (count_strings_pipe(str[i], '|') != 1)
        {
            tmp = ft_split_pipe(str[i], '|');
            j = -1;
            while (tmp[++j] != NULL)
                tab[i + j] = strdup(tmp[j]);
            z += j - 1;
            free_tab(tmp);
        }
        else
            tab[i + z] = strdup(str[i]);
        i++;
    }
    tab[i + z] = NULL;
    return;
}

// int	main(int argc, char **argv)
// {
// 	int		i;
//     int     size;
// 	char	sep;
// 	char	**strs;
//     char    **tab;

// 	(void)argc;
// 	i = 0;
// 	sep = '|';
//     size = 0;
//     strs = ft_split("bonjour cestmoi|lepipe bidoche", ' ');
//     while (strs[i] != NULL)
//     {
//         size += count_strings_pipe(strs[i], '|');
//         i++;
//     }
// 	tab = split_pipe(strs);
//     i = 0;
// 	while (tab[i] != 0)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
//     free_tab(tab);
// 	return (0);
// }
