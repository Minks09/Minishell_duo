/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:54:19 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/31 21:53:17 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    print_env(t_envp **root)
{
    t_envp *curr;

    curr = *root;
    if (curr == NULL)
        return ERROR;
    while (curr != NULL)
    {
        printf("%s=%s\n", curr->key, curr->value);
        curr = curr->next;
    }
    return SUCCESS;
}