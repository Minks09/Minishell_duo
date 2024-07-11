/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/12 00:20:41 by nigateau         ###   ########.fr       */
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
void        print_string_array(char **array);
char        *return_key(char *str);
char        *return_value(char *str);
int         is_inside_quote(const char *str, int index);
const char  *skip_quotes(const char *str);
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


# endif