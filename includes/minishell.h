/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:42 by racinedelar       #+#    #+#             */
/*   Updated: 2024/06/16 17:23:51 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"
# include "lexer.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <termios.h>

////////COLORS////////
#define C_GREEN = "\033[0m\033[32m"
#define C_RED = "\033[0m\033[31m"
#define C_WHITE = "\033[0m\033[37m"
#define C_YELLOW = "\033[0m\033[33m"
#define C_CYAN = "\033[0m\033[36m"
#define C_RESET = "\033[0m"

/////////////PROTOTYPES////////////////
void    ft_env_to_lst(char **envp, t_envs_lst **envs);
void	ft_envs_lst_add_back(t_envs_lst **lst, t_envs_lst *new);

# endif