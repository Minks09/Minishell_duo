/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:57:52 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/10 16:35:33 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

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

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    int i;
    t_queue *queue_env;
    copy_envp(queue_env, env);
    if (!queue_is_empty(queue_env))
        printf("queue is not empty\n");
    i = 0;
    while (queue_env->size >= i)
    {
        printf("key: %s\n", queue_env->head->key);
        printf("value: %s\n", queue_env->head->value);
        queue_env->head = queue_env->head->next;
        i++;
    }
    return (0);
}

// int main(int ac, char **av, char **env)
// {
//     (void)ac;
//     (void)av;
//     int i;
//     t_queue *queue_env;
//     queue_env = init_queue();
//     if (queue_is_empty(queue_env))
//         printf("queue is empty\n");
//     enqueue(queue_env, "key1", "value1");
//     if (!queue_is_empty(queue_env))
//         printf("queue is not empty\n");
//     printf("queue size : %d\n", queue_env->size);
//     return (0);
// }