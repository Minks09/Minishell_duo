/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:09:31 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/31 16:37:15 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

t_bool  check_command(t_shell *shell)
{
    int i;
    t_token *curr;

    i = 1;
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

// void free_tab(char **tab)
// {
//     int i;
    
//     i = 0;
//     while (tab[i] != NULL)
//     {
//         free(tab[i]);
//         i++;
//     }
//     free(tab);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		tot_len;
	char	*str;

	i = -1;
	j = -1;
	tot_len = strlen(s1) + strlen(s2);
	len_s1 = strlen(s1);
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
