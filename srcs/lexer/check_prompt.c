/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:18:24 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/23 20:12:59 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<minishell.h>

char    *check_prompt(char *prompt)
{
    char    *clean_prompt;
    if (!check_both_quotes(prompt) || !search_semi_back(prompt))
        return (NULL);
    escape_double_quote(prompt);
    escape_single_quote(prompt);
    clean_prompt = expandz(prompt);
    return(clean_prompt);
}

// t_bool  check_command(t_shell *shell)
// {
//     int i;
//     char    *tmp;
//     t_token *curr;

//     i = 1;
//     curr = shell->token;
//     while (curr != NULL)
//     {   
//         if (strncmp(curr->command, "|\0", 2) != 0)
//         {
//             if (access(curr->command, X_OK | F_OK) != 0)
//                 return (ft_putstr("command not valid"), FALSE);
//         }
//         curr = curr->next;
//     }
//     return (TRUE);
// }

t_bool    parsing(t_shell *shell, char *prompt, char **env)
{
	char    *clean_prompt;
	char     **commands;
	t_token     *root_token;
	t_envp      *root_env;

	clean_prompt = check_prompt(prompt);
	if (!clean_prompt)
		return(FALSE);
	commands = ft_split_command(clean_prompt, ' ');
	root_token = init_token_struct();
	parse_token(&root_token, commands);
	root_env = return_env(shell, env);
	shell->token = root_token;
	shell->env = root_env;
	if (!check_command(shell))
		return (FALSE);
	shell->nb_pipe = return_pipe_nbr(clean_prompt);
	return(TRUE);
}

int     return_pipe_nbr(char *prompt)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (prompt[i])
    {
        if (prompt[i] == '|' && (!is_inside_quote(&prompt[i], i)))
            count++;
            i++;
    }
    return (count);
}

// int main_prompt(int argc, char **argv, char **envp)
// {
//     char *prompt;
//     char *new_prompt;
//     char **commands;
//     t_shell     *shell;
//     t_token     *curr;

//     prompt = strdup("ls -la ||| grep \"bonjour sarah\"");
//     if (!parsing(shell, prompt, envp))
//         {
//             free_token_struct(&shell->token);
//             free(prompt);
//             return(1);
//         }
//     parsing(shell, prompt, envp);
//     curr = shell->token;
//     while (curr != NULL)
//     {
//         printf("command : %s\n", curr->command);
//         printf("argument : %s\n", curr->argument);
//         printf("type : %d\n", curr->type);
//         curr = curr->next;
//     }
//     printf("number of pipe : %d\n", shell->nb_pipe);
//     free_token_struct(&shell->token);
//     free_env(&shell->env);
//     free(prompt);
//     return (1);
// }