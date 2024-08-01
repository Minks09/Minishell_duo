/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:21:14 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 17:01:51 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *full_path(t_shell *shell)
{
	char *tmp;
	
	tmp = NULL;
	while (shell->token->command != NULL)
	{
		while (shell->path_bin != NULL)
		{
			tmp = ft_strjoin(*shell->path_bin, shell->token->command);
			if (access(tmp, F_OK) == 0)
			{
				if (access(tmp, X_OK) != 0){
					shell->exit_status = R_PERM;
					ft_putstr_fd("Permission denied for command", STDERR_FILENO);
					return (strerror(R_PERM));
				}
				else 
					shell->token->path = ft_strdup(tmp);
					free(tmp);
					return (shell->token->path);
			}
			free(tmp);
			shell->path_bin++;
		}
		shell->token = shell->token->next;
	}
	return SUCCESS;
}

void find_access(t_shell *shell)
{
	int		i;
	char	*tmp;
	
	i = 0;
	tmp = ft_strjoin(shell->path_bin[i], shell->token->command);
	while (shell->token != NULL && is_builtins(shell->token->command) != 0)
	{
		if (shell->path_bin == NULL)
		{
			if(full_path(shell) == NULL)
			{
				ft_putstr_fd("No executable path found", STDERR_FILENO);
				shell->exit_status = R_PATH;
				return ;
			}
		}
		while (access(tmp, X_OK) != 0)
		{
			free(tmp);
			i++;
			tmp = ft_strjoin(shell->path_bin[i], shell->token->command);
		}
		shell->token->path = ft_strdup(tmp);
		free(tmp);
	}
}