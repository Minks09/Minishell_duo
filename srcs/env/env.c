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

char  *get_env_value(char *key, t_queue *queue)
{
    t_envp *tmp_head = queue->head;
    char *found = NULL;
	
    if (!valid_env_key(key))
        return NULL;
    while (!queue->head->next)
    {
        if(ft_strncmp(key, queue->head->key, ft_strlen(key)) == 0)
        {
            found = ft_strdup(queue->head->value);
            if (!found)
                return NULL;
            break;
        }
        queue->head = queue->head->next;
    }
    queue->head = tmp_head;
    return (found);
}
