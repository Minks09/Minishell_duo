/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:38:15 by racinedelar       #+#    #+#             */
/*   Updated: 2024/08/01 17:00:13 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void CTRL_C_child(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
}

void CTRL_else_child(int sig)
{
	(void)sig;
	
}

void	signal_child(void)
{
	signal(SIGINT, CTRL_C_child);
	signal(SIGQUIT, CTRL_else_child);
}