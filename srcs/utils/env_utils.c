/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:45:28 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/16 17:23:43 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>


// t_env_var create_new(char *string)
// {
// 	int	i;
// 	int	j;
// 	t_env_var *new;
	
// 	new = malloc(sizeof(t_env_var));
// 	if (!new)
//		return (perror(R_MALLOC));
// }
		
void    ft_envs_to_lst(char **envp, t_envs_lst **envs)
{
    int i;
    if (!envp)
        return;
    i = 0;
    while (!(envp[i]))
		ft_envs_lst_add_back(envs, ft_env_add(envp[i++]));
}
