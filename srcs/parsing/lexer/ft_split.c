/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:32:37 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/11 21:38:20 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void    skip_parenthesis2(const char *input, int parenthesis_nb,char sep)
{
    int countp;

    countp = 0;
    while (*input != sep)
    {
        if (*input =='(')
        while (*input != ')' || countp != parenthesis_nb)
        {
            if (*input == ')')
                countp++;
            input++;
        }
    }
}

int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	size_of_strings2(const char *str, char sep)
{
	int	i;
    int count_pg;
    int count_pd;

	i = 0;
	while (str[i] != '\0' && check_sep(str[i], sep) == 0)
    {
        if (str[i] == '(')
        {
            count_pg = 0;
            count_pd = 0;
            while (str[i] != '\0')
            {
                if (str[i] == '(')
                    count_pg++;
                if (str[i] == ')')
                    count_pd++;
                if (count_pg == count_pd)
                    break;
                i++;
            }
        }
        i++;
    }	
	return (i);
}

int count_strings2(const char *str, char sep)
{
    int	i;
    const char *str2;

    i = 0;
    str2 = str;
    while (size_of_strings2(str2, sep) != 0)
    {
        i++;
        str2 += size_of_strings2(str2, sep);
    }
    return (i);
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
	len_str = size_of_strings2(str, sep);
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

char	**ft_split(const char *str, char sep)
{
	int		i;
	int		nbr_of_strs;
	char	**strings;

	i = 0;
	nbr_of_strs = count_strings2(str, sep);
	strings = (char **)malloc(sizeof(char *) * (nbr_of_strs + 1));
	if (strings == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (check_sep(*str, sep) == 1))
			str++;
        //skip_parenthesis2(str, 2);
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

// void    skip_parenthesis(char *input, int *i)
// {
//     int count;

//     count = 0;
//     while (input[*i] && (input[*i] == '(' || input[*i] == ')'))
//     {
//         if (input[*i] == '(')
//             count++;
//         if (input[*i] == ')')
//             count--;
//         (*i)++;
//     }
//     while (input[*i] && input[*i] != ' ' && input[*i] != '\t' && input[*i] != '\n' && input[*i] != '\0')
//         (*i)++;
//     while (input[*i] && (input[*i] == ' ' || input[*i] == '\t' || input[*i] == '\n'))
//         (*i)++;
// }


// int	main(int argc, char **argv)
// {
// 	int		i;
//     char	sep;
// 	//char	**strs;

// 	(void)argc;
// 	i = 0;
// 	sep = '|';
// 	//strs = ft_split(argv[1], sep);
// 	// while (strs[i] != 0)
// 	// {
// 	// 	printf("%s\n", strs[i]);
// 	// 	i++;
// 	// }
//     i = size_of_strings2(argv[1], sep);
//     i = count_strings2(argv[1], sep);
//     printf("%d\n", i);

// 	return (0);
// }

