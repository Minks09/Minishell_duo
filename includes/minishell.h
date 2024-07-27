/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/24 04:09:38 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

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
# include "struct.h"
////////COLORS////////
#define C_GREEN = "\033[0;32m";
#define C_RED = "\033[0;91m";
#define C_WHITE = "\033[0;37m";
#define C_YELLOW = "\033[0;33m";
#define C_CYAN = "\033[0;36m";
#define C_END = "\033[0m";

/**************************************PARSING*******************************************/

//builtins
int is_builtins(char *cmd);
int do_builtins(t_shell *shell);
int ft_pwd(t_shell *shell);

//env
int		is_alnum(char *key);
int		valid_env_key(char *key);
char	*get_env_value(char *key, t_envp *queue);

//error

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

//utils
int		ft_err_(int R_CODE);
int		put_error(t_shell *shell, char *msg, int R_CODE);

//lexer.c
t_bool	    check_both_quotes(char *input);
void	    escape_single_quote(char *input);
void	    escape_double_quote(char *input);
char	    *expand(char *str);
t_bool	    search_semi_back(char *str);
//utils.c
void        print_string_array(char **array);
char        *return_key(char *str);
char        *return_value(char *str);
int         is_inside_quote(const char *str, int index);
const char  *skip_quotes(const char *str);
void        ft_putstr(char *str);
//check_prompt.c
t_bool      parsing(t_shell *shell, char *prompt, char **env);
char        *check_prompt(char *prompt);
int         return_pipe_nbr(char *prompt);
//split_command.c
int	        check_sep_cmd(char c, char sep);
int	        count_strings_cmd(const char *str, char sep);
int	        size_of_strings_cmd(const char *str, char sep);
char	    *ft_strdup_cmd(const char *str, char sep);
char	    **ft_split_command(const char *str, char sep);
//token.c
void        parse_token(t_token **token, char **commands);
void        insert_node_token(t_token **root, char *command);
int	        return_type(char *str);
void        free_token_struct(t_token **token);
t_token     *init_token_struct(void);
//env.c
void        insert_node_env(t_envp **root, char *key, char *value);
void        free_env(t_envp **root);
t_envp      *return_env(t_shell *shell, char **env);
char        **return_env_tab(char **envp);
void        remove_node_env(t_envp **root, char *key);
//heredoc.c
void        heredoc(t_token *token);
t_bool      search_EOF(char *haystack, char *needle);
//utils2.c
void        free_tab(char **tab);
t_bool      get_pathname(t_shell *shell, char *command);
t_bool      check_command(t_shell *shell);
//error.c
t_bool    command_not_valid(char *command);

/*************************************************************************************/

/************************************BUILTINS*****************************************/

//export.c
void        export(t_envp **root, char *new_var);
char        *return_value_quoted(char *str);
//echo.c
char        *expandz(char *str);
char        *get_value(char *str);
int         size_var_value(char *str);
int         size_var_key(char *str);
void        echo(t_token **token);
//export.c
void        export(t_envp **root, char *new_var);
char        *return_value_quoted(char *str);
//print_env.c
void        print_env(t_envp **root);
//unset.c
void        unset(t_envp **root, char *key);


/*************************************************************************************/
#endif /* MINISHELL_H */