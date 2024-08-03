/* ************************************************************************** */
/*                          */
/*                    :::    ::::::::   */
/* main.c               :+:  :+:  :+:   */
/*                  +:+ +:+      +:+    */
/* By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+      */
/*                +#+#+#+#+#+  +#+        */
/* Created: 2024/05/23 15:18:48 by racinedelar       #+#   #+#     */
/* Updated: 2024/06/20 02:11:15 by racinedelar      ###   ########.fr   */
/*                          */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int  set_prompt(t_shell **shell)
{
	char *tmp;

   tmp = ft_strdup(">42_minibash<$ :");
   (*shell)->prompt = malloc(ft_strlen(tmp) + 1);
   if (!(*shell)->prompt)
      return(ft_err_(R_MALLOC));
   ft_strlcpy((*shell)->prompt, tmp, ft_strlen(tmp) + 1);
   return SUCCESS;
}

int init_termios(t_termios *termios_new, t_termios *termios_copy)
{
	if (tcgetattr(STDIN_FILENO, termios_new))
		return (ERROR);
	*termios_copy = *termios_new;
	termios_new->c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, termios_new))
		return (ERROR);
	return (SUCCESS);
}

int shell_init(t_shell **shell, t_termios *new, t_termios *copy)
{
	*shell = malloc(sizeof(t_shell));
	if (!(*shell))
		return ERROR;
	(*shell)->pid = 0;
	(*shell)->quit_child = 0;
	(*shell)->exit_status = 0;
	(*shell)->status = WAIT;
	(*shell)->env_tab = NULL;
	if (isatty(STDIN))
		(*shell)->shlvl = ft_atoi(getenv("SHLVL")) + 1;
	else
	(*shell)->shlvl += 1;
	set_prompt(shell);
	if (!isatty(STDOUT) && isatty(STDIN))
		ft_putstr_fd("WARNING: STDOUT is not a terminal,'\n'\
		WARNING: Prompt history are disable", STDERR_FILENO); 
	if (isatty(STDIN) && init_termios(new, copy))
		return SUCCESS;
	else 
	return ERROR;
}

void template_token(t_shell *shell)
{
	shell->token = malloc(sizeof(t_token));
	if (!shell->token)
		return;
	shell->token->command = "ls";
	shell->token->path = NULL;
	shell->token->argument = "-la";
	shell->token->operator = NULL;
	shell->token->file = NULL;
	shell->token->type = 0;
	shell->token->fd = 0;
	shell->token->next = NULL;
}

void  main_shell(t_shell *shell)
{
	//t_token		*commands;
	char 		*buff;
	// char		*prompt;

	buff = NULL;
	// buff = malloc(sizeof(char*) * BUFF_SIZE);
	// if(!buff)
	// 	return;
	while (shell->status != QUIT)
	{
		signal_main();
		if(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			buff = readline(shell->prompt);
		else
			buff = get_next_line(STDIN_FILENO);
		if(!buff)
			return;
		if (buff != NULL && *buff == '\0')
			return;
		if (buff && *buff){
			if (isatty(STDIN_FILENO))
				add_history(buff);
			else
				ft_putendl_fd(buff, STDOUT_FILENO);
			if(parsing(shell, buff) == 1)
			{
			signal_child();
			buildfull_command(shell);
			main_exec(shell);
			}
		}
	}
	rl_clear_history();
	// quit_shell(shell);
}

int g_errno = 0;

int main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	t_termios	new;
	t_termios	copy;

	(void) argv;
	shell = NULL;
	if (argc != 1){
		perror("TO MANY ARGUMENTS, FOLLOW THE PROJECT GUIDELINES");
		return (ERROR);
	}
	shell_init(&shell, &new, &copy);
	shell->env = return_env(shell, envp);
	set_bin_path(envp, shell);
	main_shell(shell);
	free(shell->env);
	free(shell->env_tab);
	return (g_errno % 255);
}
