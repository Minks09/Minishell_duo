/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:57:52 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/23 15:18:34 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <minishell.h>

void    copy_envp(t_queue *queue_env, char **env)
{
    int i;
    char *key;
    char *value;

    i = 0;
    queue_env = init_queue();
    while (env[i])
    {
        key = return_key(env[i]);
        //printf("key : %s", key);
        value = return_value(env[i]);
        //printf("value: %s", value);
        enqueue(queue_env, key, value);
        free(key);
        free(value);
        i++;
    }
    return ;
}

char    *return_key(char *str)
{
    int     i;
    int     size;
    char    *key;

    i = 0;
    size = 0;
    if (!str)
        return (NULL);
    while (str[size] != '=')
        size++;
    key = (char *)malloc(sizeof(char) * size + 1);
    if (!key)
        return (NULL);
    while (i < size)
    {
        key[i] = str[i];
        i++;
    }
    key[i] = '\0';
    return (key);    
}

char    *return_value(char *str)
{
    char    *tmp;
    char    *value;

    if (!str)
        return (NULL);
    tmp = strchr(str, '=');
    tmp++;
    value = strdup(tmp);
    return (value);
}

// int main(int ac, char **av, char **env)
// {
//     (void) ac;
//     (void) av;
//     t_queue *queue_env = NULL;
//     copy_envp(queue_env, env);
//     while (queue_env->tail->next)
//     {
//         printf("key: %s\n", queue_env->tail->key);
//         printf("value: %s\n", queue_env->tail->value);
//         queue_env->tail = queue_env->tail->next;
//     }
//     return (0);
// }
