/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:44:42 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/27 17:43:21 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

const char *skip_quotes(const char *str)
{
    if (*str == '\"')
    {
        str++;
        while(*str != '\"')
            str++;
    }
    if (*str == '\"')
    {
        str++;
        if (*str == ' ')
            str++;
    }
    if (*str == '\'')
    {
        str++;
        while(*str != '\'')
            str++;
    }
    if (*str == '\'')
    {
        str++;
        if (*str == ' ')
            str++;
    }
    return(str);
}

int     is_inside_quote(const char *str, int index)
{
    int i;
    int left;
    int right;

    left = 0;
    right = 0;
    i = 0;
    while (i < index)
    {
        if (*(str - i) == '\'' || *(str - i) == '\"')
            left++;
        i++;
    }
    i = 1;
    if (str[0])
    {
        while(str[i])
        {
            if (*(str + i) == '\'' || *(str + i) == '\"')
            right++;
            i++;
        }
    }
    return(right % 2 == 1 && left % 2 == 1);
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

void print_string_array(char **array) 
{
    int i;

    if (array == NULL) {
        printf("Array is NULL\n");
        return;
    }
    
    i = 0;
    while (array[i] != NULL) {
        printf("%s\n", array[i]);
        i++;
    }
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
void free_tab(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}