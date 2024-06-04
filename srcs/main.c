/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:48 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/04 16:56:04 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void shell_init(t_shell *shell)
{
   shell->pid = 0;
   shell->fd_in = -1;
   shell->fd_out = -1;
   shell->proc_lvl = 0;
}

int main(int argc, char **argv, char **envp)
{
   t_envs_lst *envs;
   //t_shell shell;

   (void) argv;
   (void) argc;
   envs = NULL;
   ft_env_to_lst(envp, &envs);
   //start(&envs);
}