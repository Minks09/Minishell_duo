/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:01:22 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 16:08:02 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	simple_exec(t_shell *shell, t_token *curr)
{
	pid_t pid;
	pid = fork();
	if(pid == 0){
		if(shell->fd_in != 0){
			dup2(shell->fd_in, STDIN_FILENO);
			close(shell->fd_in);}
		if (curr->type == T_TRUNC || curr->type == T_APPEND || curr->type == T_INPUT)
			handle_redirection(curr);
		if (execve(curr->path, curr->argument, shell->path_bin) < 0){
			perror("execve failed to execute");
			exit(EXIT_FAILURE);}
		else if (pid > 0){
			waitpid(pid, &shell->exit_status, 0);
			if(shell->fd_in != 0)
				close(shell->fd_in);
			if(shell->fd_out != 1)
				close(shell->fd_out);
			}else{
				perror("fork");
				exit(EXIT_FAILURE);}
			exit(EXIT_SUCCESS);
		}
}

void execute_first_pipe(t_shell *shell, t_token *curr){
	init_first_pipe(&shell->nb_pipe);
	shell->pid = fork();
	if (shell->pid == 0){
		if (shell->fd_in != 0){
			dup2(shell->fd_in, STDIN_FILENO);
			close(shell->fd_in);}
		dup2(shell->pipe.fd[1], STDOUT_FILENO);
		close_pipe(&shell->pipe);
	}
}
void execute_mid_pipe(t_shell *shell, t_token *curr){

}
void execute_last_pipe(){}

void pipe_exec(t_shell *shell, char **env)
{
	(void)env;
	(void)shell;
	printf("pipe_exec\n");
}

void main_exec(t_shell *shell , char **env)
{
	t_token *token;
	char *curr_token;
	token = shell->token;
	while (shell->token->command != NULL && shell->status != QUIT && token->type != T_END)
	{
		curr_token = ft_strdup(token->command);
		shell->status = EXEC;
		if (is_builtins(curr_token) == 0)
			do_builtins(*token, shell);
		while (shell->token->command != NULL);
		{
			if (shell->nb_pipe >= 2)
				pipe_exec(shell, env);
			else
				simple_exec(shell, env);
		}
	}
	shell->status = WAIT;
}