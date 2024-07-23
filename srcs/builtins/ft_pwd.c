/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:41:38 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 22:26:00 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

int ft_pwd(t_shell *shell)
{
	char *pwd;
	if(ft_strncmp(shell->token->command, "pwd", 4))
		return (ft_err_(R_ERROR));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_err_(R_ERROR));
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (SUCCESS);
}