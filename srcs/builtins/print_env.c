/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:54:19 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/21 18:01:55 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    print_env(t_envp **root)
{
    t_envp *curr;

    curr = *root;
    while (curr != NULL)
    {
        printf("%s=%s\n", curr->key, curr->value);
        curr = curr->next;
    }
    return;
}