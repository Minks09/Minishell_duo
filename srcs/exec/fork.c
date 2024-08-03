/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:04:58 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 15:28:42 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_first_pipe(t_shell *shell, t_token *curr)
{
	init_first_pipe(shell);
	if (is_builtins(curr->command) == 0)
	{
		do_builtins(shell);
	}
	else
	{
		shell->pid = fork();
		if (shell->pid == 0)
		{
			if (curr->fd != 0)
			{
				dup2(curr->fd, STDIN_FILENO);
				close(curr->fd);
			}
			dup2(shell->pipe.in[1], STDOUT_FILENO);
			close_pipes(&shell->pipe);
			if (execve(curr->path, &curr->argument, shell->path_bin) < 0)
			{
				perror("execve failed to execute");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	execute_mid_pipe(t_shell *shell, t_token *curr)
{
	init_mid_pipe(shell);
	if (is_builtins(curr->command) == 0)
	{
		do_builtins(shell);
	}
	else
	{
		shell->pid = fork();
		if (shell->pid == 0)
		{
			dup2(shell->pipe.in[0], STDIN_FILENO);
			close(shell->pipe.in[0]);
			close(shell->pipe.in[1]);
			dup2(shell->pipe.out[1], STDOUT_FILENO);
			close(shell->pipe.out[0]);
			close(shell->pipe.out[1]);
			if (execve(curr->path, &curr->argument, shell->path_bin) < 0)
			{
				perror("execve failed to execute");
				exit(EXIT_FAILURE);
			}
		}
	}
	close(shell->pipe.in[0]);
	close(shell->pipe.in[1]);
	shell->pipe.in[0] = shell->pipe.out[0];
	shell->pipe.in[1] = shell->pipe.out[1];
}

void	execute_last_pipe(t_shell *shell, t_token *curr)
{
	if (is_builtins(curr->command) == 0)
	{
		do_builtins(shell);
	}
	else
	{
		shell->pid = fork();
		if (shell->pid == 0)
		{
			dup2(shell->pipe.in[0], STDIN_FILENO);
			close_pipes(&shell->pipe);
			if (execve(curr->path, &curr->argument, shell->path_bin) < 0)
			{
				perror("execve failed to execute");
				exit(EXIT_FAILURE);
			}
		}
	}
	close_pipes(&shell->pipe);
}

void	pipe_exec(t_shell *shell)
{
	t_token	*curr;

	curr = shell->token;
	if (!curr)
		return ;
	execute_first_pipe(shell, curr);
	curr = curr->next;
	while (curr && curr->next)
	{
		execute_mid_pipe(shell, curr);
		curr = curr->next;
	}
	if (curr)
		execute_last_pipe(shell, curr);
	while ((shell->pid = waitpid(-1, &shell->exit_status, 0)) > 0)
		;
}
