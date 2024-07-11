/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:18:24 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/11 23:19:32 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

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

t_bool    parsing(t_shell *shell, char *prompt, char **env)
{
    char    *clean_prompt;
    char     **commands;
    int i;
    t_token     *root_token;
    t_envp      *root_env;

    i = 0;
    clean_prompt = check_prompt(prompt);
    if (!clean_prompt)
        return(FALSE);
    shell->nb_pipe = return_pipe_nbr(clean_prompt);
    commands = ft_split_command(clean_prompt, ' ');
    root_token = init_token_struct();
    parse_token(&root_token, commands);
    root_env = return_env(shell, env);
    shell->token = root_token;
    shell->env = root_env;
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

// int main(int argc, char **argv, char **envp)
// {
//     char *prompt;
//     char *new_prompt;
//     char **commands;
//     t_shell     *shell;
//     t_token     *curr;

//     prompt = strdup("ls -la | grep \"je suis un  test\" | cat");
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