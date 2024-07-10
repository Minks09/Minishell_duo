/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:59:35 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/10 22:19:01 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

void    insert_node_token(t_token **root, char *command)
{
    t_token *new_node;
    new_node = malloc(sizeof(t_token));
    if (!new_node)
        exit(1);
    new_node->command = command;
    new_node->path = NULL;
    new_node->argument = NULL;
    new_node->operator = NULL;
    new_node->file = NULL;
    new_node->type = 0;
    new_node->fd = 0;

    t_token *curr;
    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void    parse_token(t_token **token, char **commands)
{
    int i;

    i = 0;
    while (commands[i] != NULL)
    {
        insert_node_token(token, commands[i]);
        i++;
    }
}
// int main()
// {
//     t_token *root;
//     t_token *curr;

//     root = init_token_struct();
//     parse_token(&root, commands)
//     curr = root;
//     while (curr != NULL)
//     {
//         printf("key : %s\n", curr->command);
//         printf("value : %s\n", curr->argument);
//         curr = curr->next;
//     }
// }
