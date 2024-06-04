/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/04 19:41:19 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"
# include "lexer.h"
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

////////COLORS////////
#define C_GREEN = "\033[0;32m";
#define C_RED = "\033[0;91m";
#define C_WHITE = "\033[0;37m";
#define C_YELLOW = "\033[0;33m";
#define C_CYAN = "\033[0;36m";
#define C_END = "\033[0m";

/////////////PROTOTYPES////////////////
void    ft_env_to_lst(char **envp, t_envs_lst **envs);


# endif