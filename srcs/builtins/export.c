/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:08:17 by racinedelar       #+#    #+#             */
/*   Updated: 2024/05/28 17:11:35 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **copy_tab(char **tab)
{
    int i;
    char **result;

    i = 0;
    while (tab[i++])
        ;
    result = malloc(sizeof(char *) * i);
    i = -1;
    while (tab[++i])
        result[i] = ft_strdup(tab[i]);
    result[i] = NULL;
    return (result);
}