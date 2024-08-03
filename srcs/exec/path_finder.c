/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:21:14 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/02 20:18:59 by racinedelar      ###   ########.fr       */
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
	char	*new_test;
	t_token	*head;
	
	head = shell->token;
	i = 0;
	tmp = ft_strjoin(shell->path_bin[i], shell->token->command);
	if(shell->token->type == T_CMD)
	{
		if (is_builtins(shell->token->command) == 1)
			shell->token = shell->token->next;
		if (shell->path_bin == NULL)
		{
			if(full_path(shell) != NULL)
			{
				ft_putstr_fd("No executable path found", STDERR_FILENO);
				shell->exit_status = R_PATH;
				return ;
			}
		}
		while (access(tmp, X_OK) != 0 && shell->path_bin[i] != NULL)
		{
			new_test = ft_strjoin(shell->path_bin[i++], shell->token->command);
			tmp = ft_strdup(new_test);
		}
		if (shell->token->argument != NULL){
			free(new_test);
			new_test = ft_strjoin(tmp, shell->token->argument);
		}
		shell->token->path = ft_strdup(tmp);
		shell->token = shell->token->next;
	}
	shell->token = head;
	return;
}
void	buildfull_command(t_shell *shell)
{
	t_token *head;
	int i = 0;
	head = shell->token;
	shell->status = WAIT;
	while(shell->token != NULL)
	{
		find_access(shell);
		printf("*********token%d*******************\n", i);
		printf("[CMD]\t%s\n[PATH]\t%s\n[ARG]\t%s\n[OPER]\t%s\n", shell->token->command, shell->token->path, shell->token->argument, shell->token->operator);
		printf("[FILE]\t%s\n[TYPE]\t%d\n[FD]\t%d\n", shell->token->file, shell->token->type, shell->token->fd);
		shell->token = shell->token->next;
		i++;
	}
	shell->token = head;
}
