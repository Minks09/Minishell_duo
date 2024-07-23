/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:16:13 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/23 16:42:17 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>


//definition des types possible de token 
# define T_EMPTY 			0
# define T_CMD 				1
# define T_ARG 				2 // = " "/ -{}
# define T_TRUNC 			3 // = >
# define T_APPEND 			4 // = >>
# define T_INPUT 			5 // = <
# define T_PIPE 			6 // = |
# define T_END 				7
//definition des type de redirections
# define STDIN 				0
# define STDOUT 			1
# define STDERR_FILENO 		2
//definition of types of potential errors
# define R_MALLOC 			2
# define R_ERROR 			9
# define R_PERM 			126 // If a command is found but is not executable,the return status is 126
# define R_PATH 			127 //If a command is not found, the child process created to execute it returns a status of 127
# define R_FILE_NOT_FOUND 	255
# define BUFF_SIZE 			1042
# define EXPANSION 			-36

/* ERROR CODES */
# define ERROR 				-1
# define SUCCESS 			0
# define IS_DIRECTORY 		126
# define UNKNOWN_COMMAND 	127

# define FALSE 0
# define TRUE 1
# define t_bool int

/* SHELL STATUS TYPE */
# define WAIT 0
# define READ 1
# define EXEC 2
# define QUIT 3
# define QUIT_CHILD			130
# define UNDEFINED_ERROR	255

/* BOOLEANS CODE */
# define NO 0
# define YES 1
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

typedef struct s_pipe
{
	int		nb_pipes;
	int		in[2];
	int		out[2];
}	t_pipe;

typedef struct s_envp
{
    char	*key;
    char	*value;
    struct s_envp	*next;
}	t_envp;
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
	
	char		*prompt;
	char		**path_bin; // tableau de chemin d'acces terminer par null
	char 		**env_tab;
	int			quit_child;
	int			exit_status;
	int			status;
	int			shlvl;
	int			nb_pipe;
	pid_t		pid;
	t_pipe		pipe;
	t_token		*token;
	t_envp		*env;
	
}	t_shell;

typedef	struct termios t_termios;
extern	int g_errno;
#endif
