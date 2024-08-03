/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 17:43:55 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "struct.h"
#include "Libft/libft.h"

////////COLORS////////
#define C_GREEN = "\033[0;32m";
#define C_RED = "\033[0;91m";
#define C_WHITE = "\033[0;37m";
#define C_YELLOW = "\033[0;33m";
#define C_CYAN = "\033[0;36m";
#define C_END = "\033[0m";

/**************************************PARSING*******************************************/

//lexer.c
t_bool	    check_both_quotes(char *input);
void	    escape_single_quote(char *input);
void	    escape_double_quote(char *input);
char	    *expand(char *str);
t_bool	    search_semi_back(char *str);
//utils.c
char        *return_key(char *str);
char        *return_value(char *str);
int         is_inside_quote(const char *str, int index);
const char  *skip_quotes(const char *str);
void        free_tab(char **tab);
//check_prompt.c
t_bool      parsing(t_shell *shell, char *prompt, char **env);
char        *check_prompt(char *prompt);
int         return_pipe_nbr(char *prompt);
t_bool      command_not_valid(char *command);
//split_command.c
int	        count_strings_cmd(const char *str, char sep);
int	        size_of_strings_cmd(const char *str, char sep);
char	    *ft_strdup_cmd(const char *str, char sep);
char	    **ft_split_command(const char *str, char sep);
//token.c
void        parse_token(t_token **token, char **commands);
void        insert_node_token(t_token **root, char *command);
void        free_token_struct(t_token **token);
t_token     *init_token_struct(void);
char        *join_argument(char *argument, char *str);
//env.c
void        insert_node_env(t_envp **root, char *key, char *value);
void        free_env(t_envp **root);
t_envp      *return_env(t_shell *shell, char **env);
char        **return_env_tab(char **envp);
void        remove_node_env(t_envp **root, char *key);
//heredoc.c
int         heredoc(char *argument);
t_bool      search_EOF(char *haystack, char *needle);
//utils2.c
t_bool      get_pathname(t_shell *shell, char *command);
t_bool      check_command(t_shell *shell);
char        *end_with_pipe(char *str);
char        *find_path(t_envp *shell_env);
char	    *ft_strjoin(const char *s1, const char *s2);
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
int	        return_type(char *str);
void        remove_node_env_extend(t_envp *to_remove);

/*************************************************************************************/

/************************************BUILTINS*****************************************/

//export.c
void        export(t_envp **root, char *new_var);
char        *return_value_quoted(char *str);
//echo.c
//char        *expandz(char *str);
//char        *get_value(char *str);
//int         size_var_value(char *str);
//int         size_var_key(char *str);
int         echo(t_token *token);
void        expandx(t_shell *shell);
char	    *get_env(t_shell *shell, char *str);
//export.c
void        export(t_envp **root, char *new_var);
char        *return_value_quoted(char *str);
//print_env.c
void        print_env(t_envp **root);
//unset.c
void        unset(t_envp **root, char *key);


# endif