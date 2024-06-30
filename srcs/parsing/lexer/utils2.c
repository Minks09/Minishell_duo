/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:16 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/19 15:58:21 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

t_token *init_token_struct(void)
{
    t_token  *token;

    token = malloc(sizeof(t_token));
    if (!token)
        exit(1);
    token->command = strdup("");
    token->path = strdup("");
    token->argument = strdup(" EOF ");
    token->operator = strdup("");
    token->file = strdup("");
    token->type = 0;
    token->fd = -1;
    token->next = NULL;
    return (token);
}

void    free_token_struct(t_token **token)
{
    t_token  *curr;
    t_token  *tmp;

    curr = *token;
    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        free (tmp->command);
        tmp->command = NULL;
        free (tmp->path);
        tmp->path = NULL;
        free (tmp->argument);
        tmp->argument = NULL;
        free (tmp->operator);
        tmp->operator = NULL;
        free (tmp->file);
        tmp->file = NULL;
        free (tmp);
        tmp = NULL;
    }
    *token = NULL;
}