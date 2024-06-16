/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:48 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/09 22:37:48 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void shell_init(t_shell *shell)
{
   shell->pid = 0;
   shell->fd_in = -1;
   shell->fd_out = -1;
   shell->proc_lvl = 0;
   //ici set la copy de lenv et la rendre utilisable 
}

int main(int argc, char **argv, char **envp)
{
   t_envs_lst *envs;
   t_termios   

   (void) argv;
   if (argc != 1)
      return 
   //ft_env_to_lst(envp, &envs);
   //start(&envs);
}
