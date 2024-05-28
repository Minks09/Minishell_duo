/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:47:32 by nchebbi           #+#    #+#             */
/*   Updated: 2023/03/16 19:55:40 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		read_to_string(char **buffer, int fd);
char	*cpybufftoline(char **buffer);
char	*ft_strndup(char *str, int size);
int		ft_strchr_i(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif