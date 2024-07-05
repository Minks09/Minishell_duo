/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:21:14 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/06 01:19:51 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *full_path(t_shell *shell)
{
	char *tmp;
	
	*tmp = NULL;
	while (shell->token->command != NULL)
	{
		while (shell->path_bin != NULL)
		{
			tmp = ft_strjoin(shell->path_bin, shell->token->command);
			if (access(tmp, F_OK) == 0)
			{
				shell->token->path = ft_strdup(tmp);
				if (access(shell->token->path, X_OK) != 0)
				return (ft_err_(R_PERM));
			}
			free(tmp);
			shell->path_bin++;
		}
		shell->token = shell->token->next;
	}
}