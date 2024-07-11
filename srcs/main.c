/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:48 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 23:43:57 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// global   char *C;
// C = "coucou";

// void shell_init(t_shell *shell)
// {
//    shell->pid = 0;
//    shell->fd_in = -1;
//    shell->fd_out = -1;
//    shell->plvl = 0;
// }

// int main(int argc, char **argv, char **envp)
// {
//    t_envs_lst *envs;
//    t_shell shell;

//    void (argv);
//    void (argc);
//    envs = NULL;
//    ft_envs_to_lst(envp, &envs);
//    start(&env)
// }

t_shell *init_shell(void)
{
	t_shell  *shell;

    shell = malloc(sizeof(t_shell));
    if (!shell)
        exit(1);
    shell->prompt = NULL;
    shell->path_bin = NULL;
    shell->env_tab = NULL;
    shell->quit_child = 0;
    shell->exit_status = 0;
    shell->status = 0;
    shell->shlvl = 0;
    shell->nb_pipe = 0;
    shell->fd_in = 0;
    shell->fd_out = 0;
    shell->pid = 0;
   //  shell->pipe = malloc(sizeof(t_pipe));
   //  shell->token = malloc(sizeof(t_token));
   //  shell->env = malloc(sizeof(t_envp));

    return (shell);
}

int main(int argc, char **argv, char **envp)
{
    char *prompt;
    t_shell     *shell;
    t_token     *curr;

    (void)argc;
    (void)argv;
    prompt = strdup("ls -la | grep \"je suis un  test\" | cat");
    shell = init_shell();
    parsing(shell, prompt, envp);
    curr = shell->token;
    while (curr != NULL)
    {
        printf("command : %s\n", curr->command);
        printf("argument : %s\n", curr->argument);
        printf("type : %d\n", curr->type);
        curr = curr->next;
    }
    printf("number of pipe : %d\n", shell->nb_pipe);
    free_token_struct(&shell->token);
    free_env(&shell->env);
    free(prompt);
    return (1);
}