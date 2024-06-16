/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:58:28 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/16 16:28:44 by nigateau         ###   ########.fr       */
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
t_queue    *init_queue(void);
void    enqueue(t_queue *queue, char *key, char *value);
char    *return_key(char *str);
char    *return_value(char *str);
t_bool  queue_is_empty(t_queue *queue);

#endif