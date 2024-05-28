/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:16:13 by racinedelar       #+#    #+#             */
/*   Updated: 2024/05/27 21:16:18 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_context
{
	t_context	*next;
	t_context	*prev;
	bool		*has_pipe;
	int			*og_fd_in;
	int			*og_fd_out;
	int			fd_in;
	char		*fd_in_path;
	int			fd_out;
	char		*fd_out_path;
	char		*err_fd;
}	t_context;

typedef struct s_executor
{
	bool		has_pipe;
	t_token		*tokens;
	int			og_fd_in;
	int			og_fd_out;
	t_context	*context;
}	t_executor;