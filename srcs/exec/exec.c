/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:04 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 15:58:23 by racinedelar      ###   ########.fr       */
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
		if (is_builtins(curr_token) == 1)
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

// void	main_exec(t_shell *shell){
// Avec une commande faut pas close les pipes à la fin du if
// void	main_exec(t_shell *shell){
// 	char curr_token;
//     char prev_token:
//     char next_token;
//     charfds = [0,,1];
//     char *prev_fds = [0,1];

//     while (shell->token->command != NULL && shell->status != QUIT && shell->token->type != T_END) {
//         curr_token = ft_strdup(shell->token->command);
//         next_token = ft_strdup(shell->token->next->command);
//         shell->status = EXEC;


//         if (is_redir(next_token) shell->token->type >= 3 && shell->token->type <=6) // faire que ca le fasse pour le pipe aussi
//         {

//             if (is_heredoc(next_token)) // herdoc
//             {
//                 fds[0] = next_token.fd; // le fd du heredoc
//             }
//             else
//             {
//                 pipe(fds); // override par defauf
//             }
//         }
// else
// {
// fds[1] = 1; // si dernière commande reset fds 
// }

//         dup2(fds[0], prev_fds[0]); // le prev_fds[0] doit etre egale a a fds[0]; mais jme souviens plus l orde
//         dup2(fds[1], prev_fds[1]); // same

//         if (is_builtins(curr_token) == 0)
//             do_builtins(shell); // il manque pas le curr token ? 
//         else {
//             exec_command(shell); // same
//             // dedans il faut fork et daire le if sur le pid into le execve
//             // et close les pipe dont on se sert pas
//             // dans le thread maim ik faut close ce dont la commande dlaprss aura pas besoin et inversement pour le thread du fork
//         }

//         prev_token = next_token;
//         prev_fds = fds;
//         shell->token = shell->token->next;

//     }
//     // ici ik daur close les pipes restant
//     shell->status = WAIT;
// }