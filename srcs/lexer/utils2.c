/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:09:31 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/01 21:39:36 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool  check_command(t_shell *shell)
{
    t_token *curr;

    curr = shell->token;
    while (curr != NULL)
    {   
        if (strncmp(curr->command, "|\0", 2) != 0 &&
         strncmp(curr->command, ">", 1) != 0 &&
         strncmp(curr->command, "<", 1) != 0)
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
    char    *tmp;

    i = 0;
    pathname = find_path(shell->env);
    path_cmd = ft_split(pathname, ':');
    free(pathname);
    while (path_cmd[i])
    {
        tmp = ft_strjoin(path_cmd[i], "/");
        pathname = ft_strjoin(tmp, command);
        free(tmp);
        if (access(pathname, X_OK | F_OK) == 0)
        {
			free(pathname);
			free_tab(path_cmd);
            return (TRUE);
        }
        free(pathname);
        i++;
    }
    free_tab(path_cmd);
    return (FALSE);
}

char *find_path(t_envp *shell_env)
{
    char *pathname;
    t_envp *curr;

    pathname = NULL;
    curr = shell_env;
    while (curr->key != NULL)
    {
        if (strncmp(curr->key, "PATH", 4) == 0)
        {
            pathname = strdup(curr->value);
            break;
        }
        curr = curr->next;
    }
    return(pathname);
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

char    *end_with_pipe(char *str)
{
    int i;
    char tmp;
    char *temp;
    char *newline;

    i = strlen(str);
    while(str[i] == ' ' && i > 0)
        i--;
    tmp = str[i - 1];
    while (tmp == '|')
    {
        newline = readline("> ");
        temp = ft_strjoin(str, " ");
        free (str);
        str = ft_strjoin(temp, newline);
        free(temp);
        free(newline);
        i = strlen(str);
        while(str[i] == ' ' && i > 0)
        i--;
        tmp = str[i - 1];
    }
    return (str);
}

