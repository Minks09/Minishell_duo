/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:09:54 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 01:20:08 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int check_exit_arg(t_shell *shell)
{
	int arg;
	int i = 0;

	while (shell->token->argument[i])
	{
		if (!ft_isdigit(shell->token->argument[i]))
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(shell->token->argument, STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			return ft_err_(255);
		}
		i++;
	}
	arg = ft_atoi(shell->token->argument);
	return ft_err_(arg);
}

int ft_exit(t_shell *shell)
{
	if (shell->token->command && ft_strncmp(shell->token->command, "exit", 5))
	{
		if (shell->token->argument)
		{
			shell->exit_status = check_exit_arg(shell);
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(shell->exit_status);
		}
		else
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(0);
		}
	return (SUCCESS);
	}
	return (ERROR);
}
