/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:34:31 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/03 15:22:07 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	search_eof(char *haystack, char *needle)
{
	int		cmp;
	char	*tmp;

	tmp = haystack;
	while (*haystack != '\0')
	{
		cmp = strncmp(haystack, needle, strlen(needle));
		if (cmp == 0)
		{
			*haystack = '\0';
			return (TRUE);
		}
		haystack++;
	}
	haystack = tmp;
	free(tmp);
	return (FALSE);
}

int	heredoc(char *argument)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (ERROR);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (search_eof(line, argument))
			break ;
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
	}
	if (line)
	{
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = NULL;
	}
	return (fd);
}
// int main()
// {
//     t_token *token;
//     token = init_token_struct();
//     heredoc(token);
//     free_token_struct(&token);
//     return (1);
// }