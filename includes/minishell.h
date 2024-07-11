/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 23:10:04 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"
# include "lexer.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/termios.h>

////////COLORS////////
#define C_GREEN  "\033[0m\033[32m"
#define C_RED  "\033[0m\033[31m"
#define C_WHITE  "\033[0m\033[37m"
#define C_YELLOW  "\033[0m\033[33m"
#define C_CYAN  "\033[0m\033[36m"
#define C_RESET  "\033[0m"

/////////////PROTOTYPES////////////////

//builtins
int is_builtins(char *cmd);
int do_builtins(t_shell *shell);
int ft_pwd(t_shell *shell);

//env
int		is_alnum(char *key);
int		valid_env_key(char *key);
char	*get_env_value(char *key, t_queue *queue);

//error
int		ft_err_(int R_CODE);
int		put_error(t_shell *shell, char *msg, int R_CODE);

//exec
void	init_first_pipe(t_shell *shell);
void	init_mid_pipe(t_shell *shell);
void	close_pipes(t_pipe *pipe);
void	execute_first_pipe(t_shell *shell, t_token *curr);
void	execute_mid_pipe(t_shell *shell, t_token *curr);
void	execute_last_pipe(t_shell *shell, t_token *curr);
void	pipe_exec(t_shell *shell);
void	simple_exec(t_shell *shell);
void	main_exec(t_shell *shell);
//redir.c
void	handle_redirection(t_token *token);

//signals
void	CTRL_C(int sig);
void	CTRL_else(int sig);
void	signal_main(void);
void	CTRL_C_child(int sig);
void	CTRL_else_child(int sig);
void	signal_child(void);

//setup
void	set_bin_path(char **envp, t_shell *shell);

#endif /* MINISHELL_H */