/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:08:14 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/01 17:00:55 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    check_redirection(char  *command, char *argument)
{
    if (strncmp(command, ">>\0", 3) == 0)
        return(redirect_output(command, argument));
    if (strncmp(command, ">\0", 2) == 0)
        return(redirect_output(command, argument));
    if (strncmp(command, "<<\0", 3) == 0)
        return(heredoc(argument));
    if (strncmp(command, "<\0", 2) == 0)
        return(redirect_input(command, argument));
    return(0);
}

int    redirect_output(char *command, char *argument)
{
    if (command[1] == '\0')
        return(open(argument, O_WRONLY | O_CREAT | O_TRUNC, 0644));
    if (command[1] == '>')
        return(open(argument, O_WRONLY | O_CREAT | O_APPEND, 0644));
    return(0);
}

int    redirect_input(char *command, char *argument)
{
    int i;
    (void)command;
    i = open(argument, O_RDONLY);
    if (i != -1)
        return(i);
    return(i);
}