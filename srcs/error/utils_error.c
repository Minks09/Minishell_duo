/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:22:11 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/12 00:05:58 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_err_(int R_CODE)
{
    perror(strerror(R_CODE));
    exit(R_CODE);
}

int put_error(t_shell *shell, char *msg, int R_CODE)
{
    ft_putstr_fd(msg, STDERR_FILENO);
    ft_putchar_fd('\n', STDERR_FILENO);
    shell->exit_status = R_CODE;
    exit(R_ERROR);
}
