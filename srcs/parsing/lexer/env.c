/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:29:10 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/18 19:43:18 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

void    insert_node_env(t_envp **root, char *key, char *value)
{
    t_envp *new_node;
    new_node = malloc(sizeof(t_envp));
    if (!new_node)
        exit(1);
    new_node->next = NULL;
    new_node->key = key;
    new_node->value = value;

    t_envp *curr;
    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void    free_env(t_envp **root)
{
    int i;
    t_envp  *curr;
    t_envp  *tmp;

    i = 0;
    curr = *root;
    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        free (tmp->key);
        tmp->key = NULL;
        free (tmp->value);
        tmp->value = NULL;
        free (tmp);
        tmp = NULL;
    }
    *root = NULL;
}

int main(int argc, char **argv, char **env)
{
    int     i;
    t_envp  *root;

    i = 1;
    root = malloc(sizeof(t_envp));
    if (!root)
        exit(1);
    root->key = return_key(env[0]);
    root->value = return_value(env[0]);
    root->next = NULL;
    while (env[i])
    {
        insert_node_env(&root, return_key(env[i]), return_value(env[i]));
        i++;
    }
    t_envp *curr;
    curr = root;
    while (curr != NULL)
    {
        printf("key : %s\n", curr->key);
        printf("value : %s\n", curr->value);
        curr = curr->next;
    }
    free_env(&root);
    return (1);
}
