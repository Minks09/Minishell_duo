/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:41:38 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/06 00:49:30 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

int ft_pwd(t_shell *shell)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_err_(R_ERROR));
	ft_putendl_fd(pwd, shell->fd_out);
	free(pwd);
	return (SUCCESS);
}