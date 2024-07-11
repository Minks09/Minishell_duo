/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/10 22:23:38 by racinedelar      ###   ########.fr       */
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
int do_builtins(t_token cmd, t_shell *shell);
int ft_pwd(t_shell *shell);

//env
int		is_alnum(char *key);
int		valid_env_key(char *key);
char	*get_env_value(char *key, t_queue *queue);

//error
int		ft_err_(int R_CODE);
int		put_error(char *msg);

//exec
void	expand_dollars(t_shell *shell);
void	main_exec(t_shell *shell, char **envp);


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