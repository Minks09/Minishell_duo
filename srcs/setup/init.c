/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:32:17 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/10 22:47:32 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>

// #include  "../../../includes/minishell.h"

// t_token *init_token_struct(t_token *token)
// {
// 	token = malloc(sizeof(t_token));
// 	if (!token)
// 		exit(1);
//     token->command = strdup("");
//     token->path = strdup("");
//     token->argument = strdup("");
//     token->operator = strdup("");
//     token->file = strdup("");
//     token->type = 0;
//     token->fd = -1;
//     token->next = NULL;
//     return (token);
// }

// void    free_token_struct(t_token **token)
// {
//     t_token  *curr;
//     t_token  *tmp;

// 	curr = *token;
// 	while (curr != NULL)
// 	{
// 		tmp = curr;
// 		curr = curr->next;
// 		free (tmp->command);
// 		tmp->command = NULL;
// 		free (tmp->path);
// 		tmp->path = NULL;
// 		free (tmp->argument);
// 		tmp->argument = NULL;
// 		free (tmp->operator);
// 		tmp->operator = NULL;
// 		free (tmp->file);
// 		tmp->file = NULL;
// 		free (tmp);
// 		tmp = NULL;
// 	}
// 	*token = NULL;
// }