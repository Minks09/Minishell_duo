/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:20:09 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/27 16:32:35 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static  void    handle_sigint_read(int sig)
{
    (void)sig;
    if (isatty(STDIN_FILENO))
    {
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
    }
   last_error = ERROR;
}

static void     handle_sigint_exec(int sig)
{
    (void)sig;
    write("\n", STDERR_FILENO, 1);
}

static void handle_sigint_heredoc(int sig)
{
    (void)sig;
    t_shell *shell;
    write("\n", STDERR_FILENO, 1);
    last_error = ERROR;
    shell->quit_child = YES;
    shell->status = EXEC;
}

static void handle_sig_quit_exec(int sig)
{
    (void) sig;
    t_shell *shell;
    kill(shell->pid, SIGINT);
    ft_putendl_fd("Quit: 3", STDERR_FILENO);
    if (shell->quit_child == NO)
        last_error = QUIT_CHILD;
    shell->quit_child = YES;
}

void    signals(void)
{
    t_shell *shell;
    if (shell->status == EXEC && shell->pid)
    {
        signal(SIGINT, handle_sigint_exec);
        signal(SIGQUIT, handle_sig_quit_exec);
    }
    else if (shell->status == EXEC)
    {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
    }
    else
    {
        signal(SIGQUIT, SIG_IGN);
        if (shell->status == READ)
            signal(SIGINT, handle_sigint_read);
        else if (shell->status == HERE_DOC && !shell->pid)
            signal(SIGINT, SIG_DFL);
        else
        {
            signal(SIGINT, handle_sigint_heredoc);
            wait(NULL);
        }
    }
}