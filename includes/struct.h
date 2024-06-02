/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:16:13 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/02 19:24:48 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"
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

typedef struct s_token
{
	char			*str;
	int				type; // define by T_*
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_env_var
{
	char	*key;
	char	*val;
}	t_env_var;

typedef struct s_envs_lst
{
	t_env_var			*key;
	struct s_envs_lst	*next;
}	t_envs_lst;

typedef struct s_shell
{
	pid_t	pid;
	int		std_in;
	int		std_out;
	int		f_in;
	int		f_out;
	int		p_lvl;
	int		exit_status;
	char	*tmpfile;
	int		shlvl;
	bool	executed;
	bool	is_running;
}	t_shell;

#endif

