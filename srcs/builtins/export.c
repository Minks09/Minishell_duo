/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:08:17 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/21 17:04:48 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


char    *return_value_quoted(char *str)
{
    int     i;
    int     size;
    char    *tmp;
    char    *value;

    i = 0;
    if (!str)
        return (NULL);
    tmp = strchr(str, '=');
    tmp++;
    tmp++;
    value = strdup(tmp);
    size = strlen(value);
    value[size - 1] = '\0';
    return (value);
}

void    export(t_envp **root, char *new_var)
{
    int     i;
    char    *key;
    char    *value;

	i = 0;
	while (new_var[i] != '=')
		i++;
	if (new_var[++i] == '\"')
		value = return_value_quoted(new_var);
    else
		value = return_value(new_var);
	key = return_key(new_var);
    insert_node_env(root, key, value);
    return;
}

// char **copy_tab(char **tab)
// {
//     int i;
//     char **result;

//     i = 0;
//     while (tab[i++])
//         ;
//     result = malloc(sizeof(char *) * i);
//     i = -1;
//     while (tab[++i])
//         result[i] = ft_strdup(tab[i]);
//     result[i] = NULL;
//     return (result);
// }