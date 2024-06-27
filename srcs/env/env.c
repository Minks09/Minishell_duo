#include <minishell.h>

int is_alnum(char *key)
{
    int i;
    char c;

    i = 0;
    while(key[i++])
    {
        c = key[i];
        if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)))
            return ERROR;
    }
    return SUCCESS;
}
int valid_env_key(char *key)
{
    int i;

    i = 0;
    while(key && ft_isalpha(key[i]))
    {
        if (is_alnum(key) || key[i] == '_')
            i++;
        else
            return(put_error("invalid key character, use only alphanum or '_'"));
    }
    return(SUCCESS);
}

char  get_env_value(char *key, t_queue *queue)
{
    t_envp *tmp_head;
    char *found;

    if (valid_env_key(key))
    *tmp_head = *queue->head;
    while (queue->head)
    {
        if(ft_strncmp(key, queue->head->key, ft_strlen(key)) == 0)
        {
            found = malloc(sizeof(char) * (ft_strlen(queue->head->value) + 1));
            if (!found)
                return(ft_err_(R_MALLOC));
            found = ft_strdup(queue->head->value);
            return(*found);
        }
        else 
            queue->head = queue->head->next;
    }
    queue->head = tmp_head;
} 