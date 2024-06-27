/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:22:24 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/27 12:56:06 by racinedelar      ###   ########.fr       */
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

int do_builtins(t_token cmd)
{
	if(!ft_strncmp(cmd.command, "echo", 5))
		return (echo(cmd.argument));
	if(!ft_strncmp(cmd.command, "cd", 3))
		return (cd(cmd.argument));
	if(!ft_strncmp(cmd.command, "pwd", 4))
		return (pwd(cmd.argument));
	if(!ft_strncmp(cmd.command, "export", 7))
		return (export(cmd.argument));
	if(!ft_strncmp(cmd.command, "unset", 6))
		return (unset(cmd.argument));
	if(!ft_strncmp(cmd.command, "env", 4))
		return (print_env(cmd.argument));
	if(!ft_strncmp(cmd.command, "exit", 5))
		return (ft_exit(cmd.argument));
}
