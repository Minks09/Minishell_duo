/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:37:17 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/23 15:02:43 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	set_new_value(char *key, char *path, t_envp *env)
{
	while(!env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(key)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(path);
			return SUCCESS;
		}
		env = env->next;
	}
	return ERROR;
}

// void 	update_wd(char *wd ){
	
// }

void	do_cd(char *wd, char new_path, t_shell *shell)
{
	
	if(ft_strncmp(&new_path, "-", 1) == 0)
		chdir(getenv("OLDPWD"));
	if (set_new_value("OLDPWD", wd, shell->env) != SUCCESS)
		put_error(shell, "error during cd (set new value):\n", R_ERROR);
	chdir(&new_path);
	getcwd(wd, 4096);
	set_new_value("PWD", wd, shell->env);
}

void ft_cd(char *new_path, t_shell *shell)
{
	char pwd[4096];
	char *home;
	
	home = get_env_value("HOME", shell->env);
	if (!new_path || !ft_strncmp(new_path, "~", 2))
		chdir(home);
	else if (getcwd(pwd, 4096))
		do_cd(pwd, *new_path, shell);
	else
		put_error(shell, "error during cd (use only a relative or absolute path):\n", R_ERROR);
}