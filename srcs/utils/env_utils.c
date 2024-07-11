/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:45:28 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 15:47:12 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env_var create_new(char *string)
{
	int	i;
	int	j;
	t_env_var *new;
	
	new = malloc(sizeof(t_env_var));
	if (!new)
		return;
}
void    ft_envs_to_lst(char **envp, t_envs_lst **envs)
{
    int i;
    if (!envp)
        return;
    i = 0;
    while (!(envp[i]))
		ft_add_var(envs, envp[i++]);
}
