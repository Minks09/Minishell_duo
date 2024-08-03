/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:26:14 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 15:26:13 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_first_pipe(t_shell *shell)
{
	if (pipe(shell->pipe.in) == -1)
	{
		perror("first pipe");
		exit(EXIT_FAILURE);
	}
}

void	init_mid_pipe(t_shell *shell)
{
	if (pipe(shell->pipe.out) == -1)
	{
		perror("mid pipe");
		exit(EXIT_FAILURE);
	}
}

void	close_pipes(t_pipe *pipe)
{
	close(pipe->in[0]);
	close(pipe->in[1]);
	close(pipe->out[0]);
	close(pipe->out[1]);
}
