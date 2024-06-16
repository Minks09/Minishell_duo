/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:16:03 by nigateau          #+#    #+#             */
/*   Updated: 2024/06/16 18:15:25 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void    heredoc1(t_token *token, t_queue *queue_env)
{
    char    *line;
    char    *heredoc;
    int     fd;
    int     ret;

    line = NULL;
    heredoc = ft_strdup("");
    fd = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1)
        return ;
    while (1)
    {
        line = readline("> ");
        if (!line)
            break ;
        if (ft_strcmp(line, token->argument) == 0)
            break ;
        heredoc = ft_strjoin(heredoc, line);
        heredoc = ft_strjoin(heredoc, "\n");
        free(line);
    }
    write(fd, heredoc, ft_strlen(heredoc));
    free(heredoc);
    close(fd);
    fd = open("heredoc", O_RDONLY);
    if (fd == -1)
        return ;
    ret = get_next_line(fd, &line);
    if (ret == 0)
        return ;
    token->argument = ft_strdup(line);
    free(line);
    close(fd);
    unlink("heredoc");
    return ;
}

void    heredoc(t_token *token, t_queue *queue_env)
{
    int fd;
    char *line;

    line = NULL;
    fd = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1)
        return ;
    while (1)
    {
        line = readline("> ");
        if (!line)
            break ;
        if (ft_strcmp(line, token->argument) == 0)
            break ;
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    line = readline("> ");
}

void search_EOF(char *haystack, char *needle)
{
    int i;
    int cmp;
    char tmp;

    i = 0;
    tmp = haystack;
    while (*haystack != NULL)
    {
        cmp = ft_strncmp(haystack, needle, ft_strlen(needle));
        if (cmp == 0 && *haystack + 1 == ' ')
        {
            *haystack = '\0';
            break;
        }
        haystack++;
    }
    haystack = tmp;
    free (tmp);
}
int main()
{
    char *hay;
    char *nee;

    hay = ft_strdup("cest moi le chaud");
    nee = ft_strdup("le");
    search_EOF(hay, nee);
    printf("haystack : %s", hay);
    return (1);

}