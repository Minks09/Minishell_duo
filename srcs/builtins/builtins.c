/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:22:24 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 00:59:10 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

int is_builtins(char *cmd)
{
	return(!ft_strncmp(cmd, "echo", 5) || \
	!ft_strncmp(cmd, "cd", 3) || \
	!ft_strncmp(cmd, "pwd", 4) || \
	!ft_strncmp(cmd, "export", 7) || \
	!ft_strncmp(cmd, "unset", 6) || \
	!ft_strncmp(cmd, "env", 4) || \
	!ft_strncmp(cmd, "exit", 5));
}

int do_builtins(t_shell *shell)
{
	if (!shell->token->command)
		return (ft_err_(R_MALLOC));
	printf("do_builtins\n");
	if(!ft_strncmp(shell->token->command, "echo", 5))
		return (echo(&shell->token));
	if(!ft_strncmp(shell->token->command, "cd", 3))
		return (ft_cd(shell->token->argument, shell));
	if(!ft_strncmp(shell->token->command,"pwd", 4))
		return (ft_pwd(shell));
	if(!ft_strncmp(shell->token->command, "export", 7))
		return (export(&shell->env, shell->token->argument));
	if(!ft_strncmp(shell->token->command, "unset", 6))
		return (unset(&shell->env, shell->token->argument));
	if(!ft_strncmp(shell->token->command, "env", 4))
		return (print_env(&shell->env));
	if(!ft_strncmp(shell->token->command, "exit", 5))
		return (ft_exit(shell));
	return (SUCCESS);
}
