/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:18:24 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/11 16:16:03 by nigateau         ###   ########.fr       */
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

t_bool    parsing(t_shell *shell, char *prompt)
{
    char    *clean_prompt;
    char     **commands;
    int i;
    t_token     *root_token;
    t_envp      *root_env;
    //t_token     *curr;

    i = 0;
    clean_prompt = check_prompt(prompt);
    if (!clean_prompt)
        return(FALSE);
    commands = ft_split_command(clean_prompt, ' ');
    root = init_token_struct();
    parse_token2(&root_token, commands);
    root_env = 
    //curr = root;
    // while (curr != NULL)
    // {
    //     printf("command : %s\n", curr->command);
    //     printf("argument : %s\n", curr->argument);
    //     printf("type : %d\n", curr->type);
    //     curr = curr->next;
    // }
    // free_token_struct(&root);
    return(TRUE);
}

int main()
{
    char *prompt;
    char *new_prompt;
    char **commands;
    t_shell     *shell;

    prompt = strdup("ls -la | grep \"je suis un test\"");
    parsing(shell, prompt);
    return (1);
}