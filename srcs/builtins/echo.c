/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:02:14 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/01 16:34:38 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    echo(t_token **token)
{
    int     i;
    t_token *curr;

    curr = *token;
    i = 0;
    while (curr != NULL)
    {
        if (strcmp(curr->command, "echo") == 0)
            break;
        curr = curr->next;
    }
    //if (strcmp(curr->argument[0], "-n") == 0)
    //    echo_n(token);
    while (curr->argument[i] != '\0')
    {
        printf("%c", curr->argument[i]);
        i++;
    }   
}

// int     size_var_key(char *str)
// {
//     int     i;
//     int     size;

//     i = 0;
//     size = 0;
//     while (str[i] != '$')
//         i++;
//     i++;
//     while (str[i] != ' ' && str[i] != '\0')
//     {
//         size++;
//         i++;
//     }
//     return (size);
// }

// int     size_var_value(char *str)
// {
// 	int	i;
//     int size;
// 	char *temp;
//     char *ptr;

// 	i = 0;
//     size = size_var_key(str);
//     ptr = strdup(str);
// 	while (ptr[i] != '$')
// 		i++;
//     i++;
//     ptr[i + size] = '\0';
// 	temp = getenv(ptr + i);
// 	if (temp == NULL)
// 		perror("variable not found");
//     strlen(temp);
//     free (ptr);
// 	return (strlen(temp));
// }

// char    *get_value(char *str)
// {
// 	int	i;
//     int size;
//     char *ptr;
// 	char *temp;
//     char *var;

// 	i = 0;
//     ptr = strdup(str);
//     size = size_var_key(ptr);
// 	while (ptr[i] != '$')
// 		i++;
//     i++;
//     ptr[i + size] = '\0';
// 	temp = getenv(ptr + i);
// 	if (temp == NULL)
// 		perror("variable not found");
//     var = strdup(temp);
//     free(ptr);
// 	return (var);
// }

// int is_there_dollar(char *str)
// {
//     int i;

//     i = 0;
//     while(str[i] != '\0')
//     {
//         if (str[i] == '$')
//             return(TRUE);
//         i++;
//     }
//     return (FALSE);
// }

// char    *expandz(char *str)
// {
//     int     i;
//     int     j;
//     int     size_var;
//     char    *new_str;
//     char    *value;

//     i = 0;
//     j = 0;
//     if(!is_there_dollar(str))
//         return (str);
//     value = get_value(str);
//     size_var = size_var_key(str);
//     new_str = (char *)malloc((sizeof(char) * strlen(str)) -size_var_key(str) +size_var_value(str));
//     if(!new_str)
//         return (NULL);
//     while (str[i] != '$')
//     {
//         new_str[i] = str[i];
//         i++;
//     }
//     while (value[j] != '\0')
//     {
//         new_str[i + j] = value[j];
//         j++;
//     }
//     while (str[i + size_var] != '\0')
//     {
//         new_str[i + j] = str[i + size_var + 1];
//         i++;
//     }
//     new_str[i + j] = '\0';
//     free(str);
//     free (value);
//     return (new_str);
// }

// int main()
// {
//     char *str;

//     str = strdup("bonjour je suis $USER !");
//     str = expandz(str);

//     printf("%s\n", str);
//     free(str);
//     return (1);
// }

void    expandx(t_shell *shell)
{
    int	i;
	char *value;
	t_token *curr_token;

	curr_token = shell->token;
	while (curr_token != NULL)
	{
		if (curr_token->command[0] == '$' && curr_token->command != NULL)
			curr_token->command = get_env(shell, curr_token->command);
		if (curr_token->argument != NULL)
		{
			if (curr_token->argument[0] == '$')
				curr_token->argument = get_env(shell, curr_token->argument);
		}
		curr_token = curr_token->next;
	}
}

char	*get_env(t_shell *shell, char *str)
{
	int	i;
	int	size;
	t_envp *curr;

	str++;
	curr = shell->env;
	size = strlen(str) + 1;
	while (curr != NULL)
	{
		if (strncmp(curr->key, str, size) == 0)
		{
			str--;
			free(str);
			return(strdup(curr->value));
		}
		curr = curr->next;
	}
	return (str);
}