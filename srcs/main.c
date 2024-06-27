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

#include "../includes/minishell.h"

int  set_prompt(t_shell *shell)
{
	char *tmp;


   tmp = ft_strdup(">42_minibash< $ ");
   shell->prompt = malloc(ft_strlen(tmp) + 1);
   if (!shell->prompt)
      return(ft_err_(R_MALLOC));
   ft_strlcpy(shell->prompt, tmp, ft_strlen(shell->prompt));
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

int shell_init(t_shell *shell, t_termios *new, t_termios *copy)
{
	shell->pid = 0;
	shell->fd_in = -1;
	shell->fd_out = -1;
	shell->proc_lvl = 0;
	set_prompt(shell);
  	if (!isatty(STDOUT) && isatty(STDIN))
      put_error("WARNING: STDOUT is not a terminal,'\n'\
      WARNING: Prompt history are disable");
   	if (isatty(STDIN_FILENO) && init_termios(new, copy))
   		return SUCCESS;
	else 
	return ERROR;
}

void  main_shell(t_shell *shell)
{
	t_token		*commands;
	char 		**buff;
	int			len;
	while (!shell->exit_status)
	{
		signal();
		if(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			*buff = readline(shell->prompt);
		else
			*buff = get_next_line(STDIN_FILENO);
		if (!(*buff))
			return;
		// if (handle_wrong_input(buff))
			continue;
		if (*buff && **buff)
		{
			if (isatty(STDIN_FILENO))
				add_history(*buff);
			// commands = get_command(*buff, '|', &len)
			// main_exec(len, commands, int[2] {0, 1});
		}
		free(*buff);
	}
}

int main(int argc, char **argv, char **envp)
{  
   //t_queue		*queue_env;
   t_shell		*shell;
   t_termios	new;
   t_termios	copy;
      
	(void) envp;
	(void) argv;
   	//queue_env = NULL;
   	shell = NULL;
   	if (argc != 1)
	return (put_error("TO MANY ARGUMENTS, FOLLOW THE PROJECT GUIDELINES"));
   	//copy_envp(queue_env, envp);
   	shell_init(shell, &new, &copy);
   	//main_shell(&shell);
   	return (0);
}
