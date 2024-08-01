/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:08:14 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/24 15:07:26 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

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
    if (command[1 == '>'])
        return(open(argument, O_WRONLY | O_CREAT | O_APPEND, 0644));
    return(0);
}

int    redirect_input(char *command, char *argument)
{
    int i;

    i = open(argument, O_RDONLY);
    return(i);
}