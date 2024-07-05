/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:46 by nchebbi           #+#    #+#             */
/*   Updated: 2024/07/05 01:13:07 by racinedelar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = (NULL);
		return (0);
	}
	if (read_to_string(&buffer, fd) == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = cpybufftoline(&buffer);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	read_to_string(char **buffer, int fd)
{
	char	*tmp;
	int		rd_bytes;

	while (ft_strchr_i(*buffer, '\n') == -1)
	{
		tmp = (char *)ft_calloc_GNL((BUFFER_SIZE + 1), sizeof(char));
		rd_bytes = read(fd, tmp, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(tmp);
			return (-1);
		}
		else if (rd_bytes == 0)
		{
			free(tmp);
			return (0);
		}
		else if (*buffer == NULL)
			*buffer = ft_strndup_GNL(tmp, rd_bytes);
		else
			*buffer = ft_strjoin_GNL(*buffer, tmp);
		free(tmp);
	}
	return (0);
}

char	*cpybufftoline(char **buffer)
{
	int		eol;
	char	*line;
	char	*tmp;

	eol = ft_strchr_i(*buffer, '\n');
	if (eol == -1 || eol == ft_strlen_GNL(*buffer))
	{
		line = ft_strndup_GNL(*buffer, ft_strlen_GNL(*buffer));
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		line = ft_strndup_GNL(*buffer, eol + 1);
		tmp = ft_strndup_GNL(*buffer + eol + 1, (ft_strlen_GNL(*buffer) - eol));
		free(*buffer);
		*buffer = ft_strndup_GNL(tmp, ft_strlen_GNL(tmp));
		free(tmp);
	}
	return (line);
}
