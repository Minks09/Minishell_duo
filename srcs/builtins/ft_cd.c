/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:37:17 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/03 15:43:21 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	update_wd_value(char *key, char *path, t_envp *env)
{
	while (!env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(key)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(path);
			return (SUCCESS);
		}
		env = env->next;
	}
	return (ERROR);
}

int	update_wd(char *wd, t_shell *shell)
{
	char	*oldpwd;
	char	*new_wd;

	oldpwd = get_env_value("PWD", shell->env);
	getcwd(wd, 4096);
	new_wd = get_env_value("PWD", shell->env);
	update_wd_value("OLDPWD", oldpwd, shell->env);
	update_wd_value("PWD", new_wd, shell->env);
	free(oldpwd);
	free(new_wd);
	return (SUCCESS);
}

void	do_cd(char *pwd, char *new_path, t_shell *shell)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strncmp(new_path, "-", 1) == 0)
	{
		chdir(getenv("OLDPWD"));
		update_wd(pwd, shell);
		return ;
	}
	if (new_path[0] == '~')
	{
		chdir(get_env_value("HOME", shell->env));
		update_wd(pwd, shell);
		return ;
	}
	else if (new_path[0] != '/')
	{
		tmp = ft_strjoin(get_env_value("HOME", shell->env), new_path);
		free(new_path);
		new_path = ft_strdup(tmp);
		free(tmp);
	}
	if (update_wd(pwd, shell) != SUCCESS)
		put_error(shell, "error during cd (set new value):\n", R_ATTR_NF);
	chdir(new_path);
	getcwd(pwd, 4096);
	update_wd_value("PWD", pwd, shell->env);
}

int	ft_cd(char *new_path, t_shell *shell)
{
	size_t	size;
	size = 4096;
	char	pwd[size];
	char	*home;

	home = get_env_value("HOME", shell->env);
	if (!new_path || ft_strncmp(new_path, "~", 2) == 0)
		chdir(home);
	else if (getcwd(pwd, 4096))
		do_cd(pwd, new_path, shell);
	else
	{
		put_error(shell, "minishell : cd: '&new_path' such file or directory",
			R_FILES);
		return (ERROR);
	}
	free(home);
	return (SUCCESS);
}
