/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:22:11 by racinedelar       #+#    #+#             */
/*   Updated: 2024/07/04 02:17:05 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_err_(int R_CODE)
{
    perror(strerror(R_CODE));
    exit(R_CODE);
    //free_all();
}

int put_error(char *msg)
{
    ft_putstr_fd(C_RED, STDERR_FILENO);
    ft_putstr_fd(msg, STDERR_FILENO);
    ft_putstr_fd(C_RESET, STDERR_FILENO);
    exit(R_ERROR);
}
