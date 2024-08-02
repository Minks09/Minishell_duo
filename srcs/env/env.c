/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:38:00 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 17:08:24 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_alnum(char *key)
{
    int i;
    char c;

    i = 0;
    while(key[i++])
    {
        c = key[i];
        if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)))
            return ERROR;
    }
    return SUCCESS;
}

int valid_env_key(char *key)
{
    int i;

    i = 0;
    while(key && ft_isalpha(key[i]))
    {
        if (is_alnum(key) || key[i] == '_')
            i++;
        else
            return(ft_err_(R_WRONGARGUMENTS));
    }
    return(SUCCESS);
}

char	*get_env_value(char *key, t_envp *list)
{
	char *found;

    if (valid_env_key(key))
		return(strerror(R_ERROR));
    while (list->key)
    {
        if(ft_strncmp(key, list->key, ft_strlen(key)) == 0)
        {
            found = malloc(sizeof(char) * (ft_strlen(list->value) + 1));
            if (!found)
                return(strerror(R_MALLOC));
            found = ft_strdup(list->value);
            return(found);
        }
        else 
            list->key = list->next->key;
	}
    return(strerror(R_ERROR));
}
