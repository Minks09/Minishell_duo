/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:16:13 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/27 16:19:29 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <sys/types.h>
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
# define STDERR_FILENO 2
//definition of types of potential errors
# define R_MALLOC 2
# define R_ERROR 9
# define R_PERM 			126
// If a command is found but is not executable,the return status is 126
# define R_PATH 			127
//If a command is not found, the child process created to execute it returns a status of 127
# define R_FILE_NOT_FOUND 	255
# define BUFF_SIZE 			4096
# define EXPANSION 			-36

/* ERROR CODES */
# define ERROR 				1
# define SUCCESS 			0
# define IS_DIRECTORY 		126
# define UNKNOWN_COMMAND 	127
# define QUIT_CHILD			130
# define UNDEFINED_ERROR	255

/* BOOLEANS CODE */
# define NO 0
# define YES 1
/* EXECUTION TYPE */
# define READ 0
# define EXEC 1
# define HERE_DOC 2

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
    char	*command;
    char    *path;
    char	**argument;
    char	*operator;
    char   	*file;
    int    	type;
	int		fd[2];
    struct s_token	*next;
}	t_token;

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
	int		quit_child;
	int		exit;
	int		status;
	int		shlvl;
	char	*prompt;
	t_token	*token;
	t_envs_lst	*envs;
	
}	t_shell;

typedef struct termios t_termios;
extern int last_error;
#endif

