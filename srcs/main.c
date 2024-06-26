/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:48 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/02 03:12:54 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

global   char *C;
C = "coucou";

void shell_init(t_shell *shell)
{
   shell->pid = 0;
   shell->fd_in = -1;
   shell->fd_out = -1;
   shell->plvl = 0;
}

int main(int argc, char **argv, char **envp)
{
   t_envs_lst *envs;
   t_shell shell;

   void (argv);
   void (argc);
   envs = NULL;
   ft_envs_to_lst(envp, &envs);
   start(&env)
}