/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:01:38 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/15 16:21:10 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

t_bool    command_not_valid(char *command)
{
    int i;

    i = 0;
    write(1, "Command not found : ", 21);
    while (command[i] != '\0')
    {
        write(1, &command[i], 1);
        i++;
    }
    write(1,"\n", 1);
    return(FALSE);
}