/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:58:28 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/04 16:29:21 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#define FALSE 0
#define TRUE 1
#define t_bool int

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

#endif