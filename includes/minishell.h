/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 02:31:10 by racinedelar      ###   ########.fr       */
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

/************************************BUILTINS*****************************************/
int			is_builtins(char *cmd);
int			do_builtins(t_shell *shell);
//echo.c
int			echo(t_token **token);
int			size_var_key(char *str);
int			size_var_value(char *str);
char		*get_value(char *str);
int			is_there_dollar(char *str);
char		*expandz(char *str);
//export.c
char		*return_value_quoted(char *str);
int			export(t_envp **root, char *new_var);
//ft_cd.c
int			update_wd_value(char *key, char *path, t_envp *env);
int			update_wd(char *wd, t_shell *shell);
void		do_cd(char *pwd, char *new_path, t_shell *shell);
int			ft_cd(char *new_path, t_shell *shell);
//ft_exit.c
int			check_exit_arg(t_shell *shell);
int			ft_exit(t_shell *shell);
//ft_pwd.c
int			ft_pwd(t_shell *shell);
//print_env.c
int			print_env(t_envp **root);
//unset.c
int			unset(t_envp **root, char *key);
/**************************************PARSING*******************************************/
//env
int			is_alnum(char *key);
int			valid_env_key(char *key);
char		*get_env_value(char *key, t_envp *queue);
/**************************************EXEC**********************************************/
//exec.c
void		simple_exec(t_shell *shell);
void		main_exec(t_shell *shell);
//fork.c
void		execute_first_pipe(t_shell *shell, t_token *curr);
void		execute_mid_pipe(t_shell *shell, t_token *curr);
void		execute_last_pipe(t_shell *shell, t_token *curr);
void		pipe_exec(t_shell *shell);
//pipe.c
void		init_first_pipe(t_shell *shell);
void		init_mid_pipe(t_shell *shell);
void		close_pipes(t_pipe *pipe);
//redir.c
int		handle_redirection(t_token *token);
/**************************************LEXER**********************************************/
//check_prompt.c
t_bool      parsing(t_shell *shell, char *prompt, char **env);
char        *check_prompt(char *prompt);
int         return_pipe_nbr(char *prompt);
//env.c
void        insert_node_env(t_envp **root, char *key, char *value);
void        free_env(t_envp **root);
t_envp      *return_env(t_shell *shell, char **env);
char        **return_env_tab(char **envp);
void        remove_node_env(t_envp **root, char *key);
//error.c
t_bool		command_not_valid(char *command);
//ft_split.c
int			check_sep(char c, char sep);
int			count_strings(const char *str, char sep);
int			size_of_strings(const char *str, char sep);
char		*ft_stringdup(const char *str, char sep);
char		**ft_split_parse(const char *str, char sep);
//heredoc.c
void		heredoc(t_token *token);
t_bool		search_EOF(char *haystack, char *needle);
//lexer.c
t_bool		check_both_quotes(char *input);
void	    escape_single_quote(char *input);
void	    escape_double_quote(char *input);
t_bool	    search_semi_back(char *str);
char	    *expand(char *str);
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
//utils.c
void        print_string_array(char **array);
char        *return_key(char *str);
char        *return_value(char *str);
int         is_inside_quote(const char *str, int index);
const char  *skip_quotes(const char *str);
void        ft_putstr(char *str);
//utils2.c
void        free_tab(char **tab);
t_bool      get_pathname(t_shell *shell, char *command);
t_bool      check_command(t_shell *shell);
char        *end_with_pipe(char *str);
//ft_split.c
char	    *ft_stringdup(const char *str, char sep);
int	        size_of_strings(const char *str, char sep);
int	        count_strings(const char *str, char sep);
int	        check_sep(char c, char sep);
//split_pipe.c
char	    *ft_strdup(const char *s1);
void        fill_new_tab(char **str,char **tab, int size);
char        **split_pipe(char **str);
char	    **ft_split_pipe(const char *str, char sep);
int	        count_strings_pipe(const char *str, char sep);
//redirection.c
int         check_redirection(char  *command, char *argument);
int         redirect_output(char *command, char *argument);
int         redirect_input(char *command, char *argument);
//error.c
t_bool    command_not_valid(char *command);

/***************************************SETUP***************************************/
//child_signal.c
void		CTRL_C_child(int sig);
void		CTRL_else_child(int sig);
void		signal_child(void);
//main_signal.c
void		CTRL_C(int sig);
void		CTRL_else(int sig);
void		signal_main(void);
//setup
void		set_bin_path(char **envp, t_shell *shell);
void		free_path_bin(t_shell *shell);
/***************************************UTILS****************************************/
//error_utils.c
int			ft_err_(int R_CODE);
int			put_error(t_shell *shell, char *msg, int R_CODE);
//free_struct.c
void		free_struct(t_shell *shell);
/*************************************************************************************/
//main.c
int set_prompt(t_shell **shell);
int init_termion(struct termios *new, struct termios *copy);
int shell_init(t_shell **shell, struct termios *new, struct termios *copy);
void main_shell(t_shell *shell, char **envp);
#endif /* MINISHELL_H */