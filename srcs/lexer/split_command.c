/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:28:11 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/23 20:14:19 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <minishell.h>

int	check_sep_cmd(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	count_strings_cmd(const char *str, char sep)
{
	int	i;
	int	count;
    int inside_quote;

	i = 0;
    inside_quote = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (check_sep_cmd(sep, str[i]) == 1))
			i++;
        if (!is_inside_quote(&str[i], i) && inside_quote == 0)
        {
            count++;
            inside_quote++;
        }
		if (str[i] != '\0' && (!is_inside_quote(&str[i], i)))
			count++;
		while (str[i] != '\0' && (check_sep_cmd(sep, str[i]) == 0))
			i++;
	}
	return (count);
}
int	size_of_strings_cmd(const char *str, char sep)
{
	int	i;

	i = 0;
    if (str[i] == '\"')
    {
        i++;
        while(str[i] != '\0' && str[i] != '\"')
            i++;
        if(str[i] == '\"')
            i++;
        return(i);

    }
    if (str[i] == '\'')
    {
        i++;
        while(str[i] != '\0' && str[i] != '\'')
            i++;
        if(str[i] == '\"')
            i++;
        return(i);
    }
	while (str[i] != '\0' && (check_sep_cmd(str[i], sep) == 0 ))
		i++;
	return (i);
}

char	*ft_strdup_cmd(const char *str, char sep)
{
	int		i;
	int		len_str;
	char	*string;

	i = 0;
	len_str = size_of_strings_cmd(str, sep);
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

char	**ft_split_command(const char *str, char sep)
{
	int		i;
	int		nbr_of_strs;
	char	**strings;

	i = 0;
	nbr_of_strs = count_strings_cmd(str, sep);
	strings = (char **)malloc(sizeof(char *) * (nbr_of_strs + 1));
	if (strings == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (check_sep_cmd(*str, sep) == 1))
			str++;
		if (*str != '\0')
		{
			strings[i++] = ft_strdup_cmd(str, sep);
		}
        if (*str == '\"')
            str = skip_quotes(str);
        else
		    while (*str != '\0' && (check_sep_cmd(*str, sep) == 0))
			    str++;
	}
	strings[i] = NULL;
	return (strings);
}

// int main()
// {
//     char *str;

//     str = strdup("je suis \"entre parenthese\" nils");
//     while (*str)
//     {
//         skip_quotes(str);
//         write(1, &str, 1);
//         str++;
//     }
//     return(1);
// }