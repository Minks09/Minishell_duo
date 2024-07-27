/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:09:31 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/23 20:17:25 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <minishell.h>

t_bool  check_command(t_shell *shell)
{
    t_token *curr;

    curr = shell->token;
    while (curr != NULL)
    {   
        if (strncmp(curr->command, "|\0", 2) != 0)
        {
            if (get_pathname(shell, curr->command) == 0)
                return (command_not_valid(curr->command));
        }
        curr = curr->next;
    }
    return (TRUE);
}

t_bool  get_pathname(t_shell *shell, char *command)
{
    int     i;
    char    **path_cmd;
    char    *pathname;
    t_envp  *curr_env;

    i = 0;
    curr_env = shell->env;
    while (curr_env != NULL)
    {
        if (strncmp(curr_env->key, "PATH", 4) == 0)
        {
            pathname = curr_env->value;
            break;
        }
        curr_env = curr_env->next;
    }
    path_cmd = ft_split(pathname, ':');
    i = 0;
    while (path_cmd[i])
    {
        pathname = ft_strjoin(path_cmd[i], "/");
        pathname = ft_strjoin(pathname, command);
        if (access(pathname, X_OK | F_OK) == 0)
            return (TRUE);
        i++;
    }
    free_tab(path_cmd);
    return (FALSE);
}

void free_tab(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		tot_len;
	char	*str;

	i = -1;
	j = -1;
	tot_len = strlen(s1) + strlen(s2);
	str = (char *)malloc(sizeof(char) * tot_len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}