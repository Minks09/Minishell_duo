#include <minishell.h>

void simple_exec(t_shell *shell) {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        if (shell->token->fd != 0) {
            dup2(shell->fd_in, STDIN_FILENO);
            close(shell->fd_in);
        }
        if (shell->token->type == T_TRUNC || shell->token->type == T_APPEND || shell->token->type == T_INPUT)
            handle_redirection(shell->token);
        if (execve(shell->token->path, &shell->token->argument, shell->path_bin) < 0) {
            perror("execve failed to execute");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        waitpid(pid, &shell->exit_status, 0);
        if (shell->fd_in != 0)
            close(shell->fd_in);
        if (shell->fd_out != 1)
            close(shell->fd_out);
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

void main_exec(t_shell *shell) {
    t_token *token = shell->token;
    char *curr_token;

    while (token->command != NULL && shell->status != QUIT && token->type != T_END) {
        curr_token = ft_strdup(token->command);
        shell->status = EXEC;
        if (is_builtins(curr_token) == 0)
            do_builtins(shell);
        else {
            if (shell->nb_pipe > 1)
                pipe_exec(shell);
            else
                simple_exec(shell);
        }
        token = token->next;
    }
    shell->status = WAIT;
}