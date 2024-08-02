/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:08:14 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/02 00:11:52 by racinedelar      ###   ########.fr       */
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

    i = -1;
    if (command)
        i = open(argument, O_RDONLY);
    return(i);
}

int	return_type(char *str)
{
	if (strncmp(str, ">", 1) == 0)
		return (T_TRUNC);
	if (strncmp(str, ">>", 2) == 0)
		return (T_APPEND);
	if (strncmp(str, "<", 1) == 0)
		return (T_INPUT);
	if (strncmp(str, "|", 1) == 0)
		return (T_PIPE);
	return (T_CMD);
}
void    remove_node_env_extend(t_envp *to_remove)
{
    free(to_remove->key);
    free(to_remove->value);
    free(to_remove);
}
