/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:18:24 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/10 22:00:05 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

int     is_inside_quote(const char *str, int index)
{
    int i;
    int left;
    int right;

    left = 0;
    right = 0;
    i = 0;
    while (i < index)
    {
        if (*(str - i) == '\'' || *(str - i) == '\"')
            left++;
        i++;
    }
    i = 1;
    if (str[0])
    {
        while(str[i])
        {
            if (*(str + i) == '\'' || *(str + i) == '\"')
            right++;
            i++;
        }
    }
    return(right % 2 == 1 && left % 2 == 1);
}
char    *check_prompt(char *prompt)
{
    char    *clean_prompt;
    if (!check_both_quotes(prompt) || !search_semi_back(prompt))
        return (NULL);
    escape_double_quote(prompt);
    escape_single_quote(prompt);
    clean_prompt = expandz(prompt);
    return(clean_prompt);
}

void    parsing(char *prompt)
{
    char    *clean_prompt;
    char     **commands;
    int i;
    t_token     *root;
    t_token     *curr;

    i = 0;
    clean_prompt = check_prompt(prompt);
    if (!clean_prompt)
        return;
    commands = ft_split_command(clean_prompt, ' ');
    root = init_token_struct();
    parse_token(&root, commands);
    curr = root;
    while (curr != NULL)
    {
        printf("command : %s\n", curr->command);
        curr = curr->next;
    }
    free_token_struct(&root);
    return;
}

int main()
{
    char *prompt;
    char *new_prompt;
    char **commands;

    prompt = strdup("ls -la | grep \"je suis un test\"");
    parsing(prompt);
    return (1);
}