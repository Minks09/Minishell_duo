/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:16:19 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/02 02:16:25 by nigateau         ###   ########.fr       */
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