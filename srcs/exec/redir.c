/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:22:52 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 23:47:32 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

void	handle_redirection(t_token *token)
{
	int file_fd;
	file_fd = -1;
	if (token->type == T_TRUNC)
		file_fd = open(token->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (token->type == T_APPEND)
		file_fd = open(token->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (token->type == T_INPUT)
		file_fd = open(token->file, O_RDONLY);
	if (file_fd < 0){
		ft_err_(file_fd % 255);
	}
	if (token->type == T_TRUNC || token->type == T_APPEND)
		dup2(file_fd, STDOUT_FILENO);
	else if (token->type == T_INPUT)
		dup2(file_fd, STDIN_FILENO);
	close(file_fd);
}