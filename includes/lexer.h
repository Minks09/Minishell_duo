/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:58:28 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/10 19:14:17 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define t_bool int

typedef struct s_token
{
    char	*command;
    char    *path;
    char	*argument;
    char   *operator;
    char   *file;
    int    type;
    int    fd;
    struct s_token	*next;
}	t_token;

typedef struct s_envp
{
    char	*key;
    char	*value;
    struct s_envp	*next;
}	t_envp;

typedef struct s_queue
{
    t_envp    *head;
    t_envp    *tail;
    int		    size;
}	t_queue;

t_bool	check_both_quotes(char *input);
void	escape_single_quote(char *input);
void	escape_double_quote(char *input);
char	*expand(char *str);
t_bool	search_semi_back(char *str);
//lexer2.c
t_queue    *init_queue(void);
void    enqueue(t_queue *queue, char *key, char *value);
char    *return_key(char *str);
char    *return_value(char *str);
t_bool  queue_is_empty(t_queue *queue);
//utils2.c
t_token *init_token_struct(void);
void    free_token_struct(t_token **token);
//env
void    insert_node_env(t_envp **root, char *key, char *value);
void    free_env(t_envp **root);
//split_command.c
int	check_sep_cmd(char c, char sep);
int	count_strings_cmd(const char *str, char sep);
int	size_of_strings_cmd(const char *str, char sep);
char	*ft_strdup_cmd(const char *str, char sep);
char	**ft_split_command(const char *str, char sep);
void print_string_array(char **array);
const char *skip_quotes(const char *str);
//check_prompt.c
int     is_inside_quote(const char *str, int index);
// token.c
void    parse_token(t_token **token, char **commands);
void    insert_node_token(t_token **root, char *command);



//bultins
//export.c
void    export(t_envp **root, char *new_var);
char    *return_value_quoted(char *str);
//echo.c
char    *expandz(char *str);
char    *get_value(char *str);
int     size_var_value(char *str);
int     size_var_key(char *str);
void    echo(t_token **token);

#endif