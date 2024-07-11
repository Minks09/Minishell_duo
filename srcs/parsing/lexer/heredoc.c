/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:34:31 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/11 01:18:51 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include  "../../../includes/minishell.h"

// void    heredoc1(t_token *token, t_queue *queue_env)
// {
//     char    *line;
//     char    *heredoc;
//     int     fd;
//     int     ret;

//     line = NULL;
//     heredoc = ft_strdup("");
//     fd = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
//     if (fd == -1)
//         return ;
//     while (1)
//     {
//         line = readline("> ");
//         if (!line)
//             break ;
//         if (ft_strcmp(line, token->argument) == 0)
//             break ;
//         heredoc = ft_strjoin(heredoc, line);
//         heredoc = ft_strjoin(heredoc, "\n");
//         free(line);
//     }
//     write(fd, heredoc, ft_strlen(heredoc));
//     free(heredoc);
//     close(fd);
//     fd = open("heredoc", O_RDONLY);
//     if (fd == -1)
//         return ;
//     ret = get_next_line(fd, &line);
//     if (ret == 0)
//         return ;
//     token->argument = ft_strdup(line);
//     free(line);
//     close(fd);
//     unlink("heredoc");
//     return ;
// }

t_bool search_EOF(char *haystack, char *needle)
{
    int i;
    int cmp;
    char *tmp;

    i = 0;
    tmp = haystack;
    while (*haystack != '\0')
    {
        cmp = strncmp(haystack, needle, strlen(needle));
        if (cmp == 0)
        {
            *haystack = '\0';
            return(TRUE);
        }
        haystack++;
        i++;
    }
    haystack = tmp;
    free (tmp);
    return (FALSE);
}

void    heredoc(t_token *token)
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
        if (search_EOF(line, token->argument))
            break;
        write(fd, line, strlen(line));
        write(fd, "\n", 1);
    }
    if (line)
    {
    write(fd, line, strlen(line));
    write(fd, "\n", 1);
    free (line);
    line = NULL;
    }
}
// int main()
// {
//     t_token *token;
//     token = init_token_struct();
//     heredoc(token);
//     free_token_struct(&token);
//     return (1);
// }