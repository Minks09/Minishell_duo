/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:14:30 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/24 15:27:23 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void free_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		if (shell->prompt)
			free(shell->prompt);
		if (shell->path_bin != NULL)
			free_tab(shell->path_bin);
		free_tab(shell->env_tab);
		if (shell->token != NULL)
			free_token_struct(shell->token);
		if (shell->env != NULL)
			free_env(shell->env);
		free(shell);
	}
}
