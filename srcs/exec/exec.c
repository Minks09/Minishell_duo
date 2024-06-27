
#include <minishell.h>

void main_exec(t_shell shell)
{
    if (is_builtins(shell.token->command))
        return(do_builtins(shell.token->argument))
}