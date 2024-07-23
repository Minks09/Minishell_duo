/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:22:24 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 22:26:06 by racinedelar      ###   ########.fr       */
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
	// if(!ft_strncmp(cmd, "echo", 5))
	// 	return (echo(cmd));
	// if(!ft_strncmp(cmd, "cd", 3))
	// 	return (cd(cmd.argument));
	if(!ft_strncmp(shell->token->command,"pwd", 4))
		return (ft_pwd(shell));
	// if(!ft_strncmp(cmd, "export", 7))
	// 	return (export(cmd.argument));
	// if(!ft_strncmp(cmd, "unset", 6))
	// 	return (unset(cmd.argument));
	// if(!ft_strncmp(cmd, "env", 4))
	// 	return (print_env(cmd.argument));
	// if(!ft_strncmp(cmd, "exit", 5))
	// 	return (ft_exit(cmd.argument));
	return (SUCCESS);
}
