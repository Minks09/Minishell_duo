/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:16:13 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/11 23:29:19 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>


//definition des types possible de token 
# define T_EMPTY 0
# define T_CMD 1
# define T_ARG 2
# define T_TRUNC 3
# define T_APPEND 4
# define T_INPUT 5
# define T_PIPE 6
# define T_END 7
//definition des type de redirections
# define STDIN 0
# define STDOUT 1
# define STDERR 2
//definition des types dexecution	
# define SKIP 1
# define NOSKIP 0
//definition of types of potential errors
# define R_MALLOC 2
# define R_CMD_NOT_FOUND 126// If a command is found but is not executable,the return status is 126
# define R_CHILD_ABORTED 127//If a command is not found, the child process created to execute it returns a status of 127
	//-> // output : Command not found
# define R_FILE_NOT_FOUND 

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

# define FALSE 0
# define TRUE 1
# define t_bool int

/* SHELL STATUS TYPE */
# define WAIT 0
# define READ 1
# define EXEC 2
# define QUIT 3


typedef struct s_quotes
{
	bool	dble;
	bool	solo;
}	t_quotes;

typedef struct s_parse
{
	t_quotes	quotes;
	int			i;
	int			begin_str;
	int			pipe;
	int			size;
	bool		flag;
	int			token_amount;
	int			index_token;
}			t_parse;

typedef struct s_pipe
{
	int		nb_pipes;
	int		in[2];
	int		out[2];
}	t_pipe;

typedef struct s_token
{
    char	*command;
    char    *path;
    char	*argument;
    char   *operator;
    char   *file;
    int    type;
    int    fd;
    struct s_token	*next;
}	t_token;

typedef struct s_envp
{
    char	*key;
    char	*value;
    struct s_envp	*next;
}	t_envp;

typedef struct s_shell
{
	char		*prompt;
	char		**path_bin; // tableau de chemin d'acces terminer par null
	char 		**env_tab;
	int			quit_child;
	int			exit_status;
	int			status;
	int			shlvl;
	int			nb_pipe;
	int			fd_in;
	int			fd_out;
	pid_t		pid;
	t_pipe		pipe;
	t_token		*token;
	t_envp		*env;
	
}	t_shell;

typedef struct termios t_termios;

#endif
