/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:57:52 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/04 18:21:35 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void    copy_envp(t_queue *queue_env, char **env)
{
    int i;
    char *key;
    char *value;
    char *tmp;

    i = 0;
    queue_env = init_queue();
    while (env[i])
    {
        key = strdup(strtok(env[i], "="));
        printf("key: %s\n", key);
        tmp = strtok(NULL, "=");
        if (!tmp)
            value = strdup("");
        else
            value = strdup(tmp);
        //value = strdup(strtok(NULL, "="));
        printf("value: %s\n", value);
        enqueue(queue_env, key, value);
        free(key);
        free(value);
        i++;
    }
}


int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    t_queue *queue_env = NULL;
    copy_envp(queue_env, env);
    while (queue_env->head)
    {
        printf("key: %s\n", queue_env->head->key);
        printf("value: %s\n", queue_env->head->value);
        queue_env->head = queue_env->head->next;
    }
    return (0);
}