/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:56:08 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/04 19:56:18 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

void	ft_envs_lst_add_back(t_envs_lst **lst, t_envs_lst *new)
{
    t_envs_lst	*last;

    if (lst)
    {
        if (*lst)
        {
            last = *lst;
            while (last->next)
                last = last->next;
            last->next = new;
        }
        else
            *lst = new;
    }
}