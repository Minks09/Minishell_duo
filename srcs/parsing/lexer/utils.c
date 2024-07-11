/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:44:42 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/11 21:43:34 by nigateau         ###   ########.fr       */
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

