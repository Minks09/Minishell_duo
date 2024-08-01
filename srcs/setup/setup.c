/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:49:02 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/28 15:43:05 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_bin_path(char **envp, t_shell *shell)
{
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strtrim(envp[i], "PATH=");
			shell->path_bin = ft_split(tmp, ':');
			free(tmp);
			break;
		}
		i++;
	}
	i = 0;
	while (shell->path_bin[i] != NULL)
	{
		tmp = ft_strjoin(shell->path_bin[i], "/");
		free(shell->path_bin[i]);
		shell->path_bin[i] = tmp;
		i++;
	}
}

void free_path_bin(t_shell *shell)
{
	int i;

	i = 0;
	while (shell->path_bin[i] != NULL)
	{
		free(shell->path_bin[i]);
		i++;
	}
	free(shell->path_bin);
}


