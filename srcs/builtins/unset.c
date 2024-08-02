/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:16:50 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/02 03:11:09 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int   unset(t_envp **root, char *key)
{
    remove_node_env(root, key);
    return  SUCCESS;
}
