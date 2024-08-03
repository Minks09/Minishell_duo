/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:04 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 15:32:39 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	simple_exec(t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (shell->token->fd != 0)
		{
			dup2(shell->fd_in, STDIN_FILENO);
			close(shell->fd_in);
		}
		if (shell->token->type == T_TRUNC || shell->token->type == T_APPEND
			|| shell->token->type == T_INPUT)
			handle_redirection(shell->token);
		if (execve(shell->token->path, &shell->token->argument,
				shell->path_bin) < 0)
		{
			perror("execve failed to execute");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &shell->exit_status, 0);
		if (shell->fd_in != 0)
			close(shell->fd_in);
		if (shell->fd_out != 1)
			close(shell->fd_out);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	main_exec(t_shell *shell)
{
	char	*curr_token;
	// t_token *head_token;
	// int i;
	// i = 0;
	// head_token = shell->token;
	// while(shell->token != NULL){
	//     printf("token %d : [CMD] = %s\n\t [ARG] = %s\n\t [TYPE] = %d\n", i++,
	//		shell->token->command, shell->token->argument, shell->token->type);
	//     shell->token = shell->token->next;}
	// shell->token = head_token;
	while (shell->token->command != NULL && shell->status != QUIT
		&& shell->token->type != T_END)
	{
		if (shell->token->type == T_PIPE)
		{
			if (shell->token->next != NULL)
				shell->token = shell->token->next;
			break ;
		}
		if (shell->token->type == T_CMD)
			curr_token = ft_strdup(shell->token->command);
		shell->status = EXEC;
		if (is_builtins(curr_token) == 0)
			do_builtins(shell);
		else
		{
			if (shell->nb_pipe > 1)
				pipe_exec(shell);
			else
				simple_exec(shell);
		}
		if (shell->token->next != NULL)
			shell->token = shell->token->next;
		else
			break ;
	}
	shell->status = WAIT;
}
