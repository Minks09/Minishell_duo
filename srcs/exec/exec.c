/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:01:22 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 22:33:07 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void init_first_pipe(t_shell *shell) {
    if (pipe(shell->pipe.in) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void init_mid_pipe(t_shell *shell) {
    if (pipe(shell->pipe.out) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void close_pipes(t_pipe *pipe) {
    close(pipe->in[0]);
    close(pipe->in[1]);
    close(pipe->out[0]);
    close(pipe->out[1]);
}

void execute_first_pipe(t_shell *shell, t_token *curr) {
    init_first_pipe(shell);
    shell->pid = fork();
    if (shell->pid == 0) {
        if (curr->fd_in != 0) {
            dup2(curr->fd_in, STDIN_FILENO);
            close(curr->fd_in);
        }
        dup2(shell->pipe.in[1], STDOUT_FILENO);
        close_pipes(&shell->pipe);
        if (execve(curr->path, curr->argument, shell->path_bin) < 0) {
            perror("execve failed to execute");
            exit(EXIT_FAILURE);
        }
    }
}

void execute_mid_pipe(t_shell *shell, t_token *curr) {
    init_mid_pipe(shell);
    shell->pid = fork();
    if (shell->pid == 0) {
        dup2(shell->pipe.in[0], STDIN_FILENO);
        close(shell->pipe.in[0]);
        close(shell->pipe.in[1]);
        dup2(shell->pipe.out[1], STDOUT_FILENO);
        close(shell->pipe.out[0]);
        close(shell->pipe.out[1]);
        if (execve(curr->path, curr->argument, shell->path_bin) < 0) {
            perror("execve failed to execute");
            exit(EXIT_FAILURE);
        }
    }
    close(shell->pipe.in[0]);
    close(shell->pipe.in[1]);
    shell->pipe.in[0] = shell->pipe.out[0];
    shell->pipe.in[1] = shell->pipe.out[1];
}

void execute_last_pipe(t_shell *shell, t_token *curr) {
    shell->pid = fork();
    if (shell->pid == 0) {
        dup2(shell->pipe.in[0], STDIN_FILENO);
        close_pipes(&shell->pipe);
        if (execve(curr->path, curr->argument, shell->path_bin) < 0) {
            perror("execve failed to execute");
            exit(EXIT_FAILURE);
        }
    }
    close_pipes(&shell->pipe);
}

void pipe_exec(t_shell *shell) {
    t_token *curr = shell->token;
    if (!curr)
        return;
    
    execute_first_pipe(shell, curr);
    curr = curr->next;

    while (curr && curr->next) {
        execute_mid_pipe(shell, curr);
        curr = curr->next;
    }

    if (curr)
        execute_last_pipe(shell, curr);

    while ((shell->pid = waitpid(-1, &shell->exit_status, 0)) > 0);
}

void	simple_exec(t_shell *shell)
{
	pid_t pid;
	pid = fork();
	if(pid == 0){
		if(shell->token->fd_in != 0){
			dup2(shell->token->fd_in, STDIN_FILENO);
			close(shell->token->fd_in);}
		if (shell->token->type == T_TRUNC || shell->token->type == T_APPEND || shell->token->type == T_INPUT)
			handle_redirection(shell->token);
		if (execve(shell->token->path, shell->token->argument, shell->path_bin) < 0){
			perror("execve failed to execute");
			exit(EXIT_FAILURE);}
		else if (pid > 0){
			waitpid(pid, &shell->exit_status, 0);
			if(shell->token->fd_in != 0)
				close(shell->token->fd_in);
			if(shell->token->fd_out != 1)
				close(shell->token->fd_out);
			}else{
				perror("fork");
				exit(EXIT_FAILURE);}
			exit(EXIT_SUCCESS);
		}
}

void main_exec(t_shell *shell) {
    t_token *token = shell->token;
    char *curr_token;

    while (token->command != NULL && shell->status != QUIT && token->type != T_END) {
        curr_token = ft_strdup(token->command);
        shell->status = EXEC;
        if (is_builtins(curr_token) == 0) {
            do_builtins(shell);
        } else {
            if (shell->nb_pipe >= 2)
                pipe_exec(shell);
            else
                simple_exec(shell);
        }
        token = token->next;
    }
    shell->status = WAIT;
}
// void	simple_exec(t_shell *shell, t_token *curr)
// {
// 	pid_t pid;
// 	pid = fork();
// 	if(pid == 0){
// 		if(shell->fd_in != 0){
// 			dup2(shell->fd_in, STDIN_FILENO);
// 			close(shell->fd_in);}
// 		if (curr->type == T_TRUNC || curr->type == T_APPEND || curr->type == T_INPUT)
// 			handle_redirection(curr);
// 		if (execve(curr->path, curr->argument, shell->path_bin) < 0){
// 			perror("execve failed to execute");
// 			exit(EXIT_FAILURE);}
// 		else if (pid > 0){
// 			waitpid(pid, &shell->exit_status, 0);
// 			if(shell->fd_in != 0)
// 				close(shell->fd_in);
// 			if(shell->fd_out != 1)
// 				close(shell->fd_out);
// 			}else{
// 				perror("fork");
// 				exit(EXIT_FAILURE);}
// 			exit(EXIT_SUCCESS);
// 		}
// }

// void execute_first_pipe(t_shell *shell, t_token *curr){
// 	init_first_pipe(&shell->nb_pipe);
// 	shell->pid = fork();
// 	if (shell->pid == 0){
// 		if (shell->fd_in != 0){
// 			dup2(shell->fd_in, STDIN_FILENO);
// 			close(shell->fd_in);}
// 		dup2(shell->pipe.fd[1], STDOUT_FILENO);
// 		close_pipe(&shell->pipe);
// 	}
// }
// void execute_mid_pipe(t_shell *shell, t_token *curr){

// }
// void execute_last_pipe(){}

// void pipe_exec(t_shell *shell, char **env)
// {
// 	(void)env;
// 	(void)shell;
// 	printf("pipe_exec\n");
// }

// void main_exec(t_shell *shell , char **env)
// {
// 	t_token *token;
// 	char *curr_token;
// 	token = shell->token;
// 	while (shell->token->command != NULL && shell->status != QUIT && token->type != T_END)
// 	{
// 		curr_token = ft_strdup(token->command);
// 		shell->status = EXEC;
// 		if (is_builtins(curr_token) == 0)
// 			do_builtins(*token, shell);
// 		while (shell->token->command != NULL);
// 		{
// 			if (shell->nb_pipe >= 2)
// 				pipe_exec(shell, env);
// 			else
// 				simple_exec(shell, env);
// 		}
// 	}
// 	shell->status = WAIT;
// }