/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:18:24 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/01 23:23:35 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

char    *check_prompt(char *prompt)
{
    char    *clean_prompt;
    if (!check_both_quotes(prompt) || !search_semi_back(prompt))
        return (NULL);
    //ft_strtrim(prompt, '\t');
    escape_double_quote(prompt);
    escape_single_quote(prompt);
    clean_prompt = end_with_pipe(prompt);
    return(clean_prompt);
}

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
    commands = split_pipe(commands);
    root_token = init_token_struct();
    parse_token(&root_token, commands);
    root_env = return_env(shell, env);
    shell->token = root_token;
    shell->env = root_env;
    shell->nb_pipe = return_pipe_nbr(clean_prompt);
    expandx(shell);
    free(clean_prompt);
    free_tab(commands);
    if (!check_command(shell))
        return (FALSE);
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

t_bool    command_not_valid(char *command)
{
    int i;

    i = 0;
    write(1, "Command not found : ", 21);
    while (command[i] != '\0')
    {
        write(1, &command[i], 1);
        i++;
    }
    write(1,"\n", 1);
    return(FALSE);
}

int main(int argc, char **argv, char **envp)
{
    char *prompt;
    t_shell     *shell;
    t_token     *curr;

    (void)argc;
    (void)argv;
    prompt = strdup("cat file1.txt | grep $USER > sorted_file1.txt");
    shell = malloc(sizeof(t_shell));
    if (!parsing(shell, prompt, envp))
        {
            free_token_struct(&shell->token);
            free_env(&shell->env);
            free_tab(shell->env_tab);
            free(shell);
            return(1);
        }
    curr = shell->token;
    while (curr != NULL)
    {
        printf("command : %s\n", curr->command);
        if (curr->argument != NULL)
            printf("argument : %s\n", curr->argument);
        if (curr->file != NULL)
            printf("file : %s\n", curr->file);
        printf("type : %d\n", curr->type);
        printf("fd : %d\n", curr->fd);
        curr = curr->next;
    }
    printf("number of pipe : %d\n", shell->nb_pipe);
    free_token_struct(&shell->token);
    free_env(&shell->env);
    free_tab(shell->env_tab);
    free(shell);
    return (1);
}
