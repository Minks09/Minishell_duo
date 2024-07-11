/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:59:35 by nigateau          #+#    #+#             */
/*   Updated: 2024/07/12 00:23:27 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

t_token *init_token_struct(void)
{
    t_token  *token;

    token = malloc(sizeof(t_token));
    if (!token)
        exit(1);
    
    token->command = NULL;
    token->path = NULL;
    token->argument = NULL;
    token->operator = NULL;
    token->file = NULL;

    token->type = 0;
    token->fd = -1;
    token->next = NULL;
    return (token);
}

void    free_token_struct(t_token **token)
{
    t_token  *curr;
    t_token  *tmp;

    curr = *token;
    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        free (tmp->command);
        tmp->command = NULL;
        free (tmp->path);
        tmp->path = NULL;
        free (tmp->argument);
        tmp->argument = NULL;
        free (tmp->operator);
        tmp->operator = NULL;
        free (tmp->file);
        tmp->file = NULL;
        free (tmp);
        tmp = NULL;
    }
    *token = NULL;
}

int	return_type(char *str)
{
	int	i;

	i = 0;
	if (strncmp(str, ">", 1) == 0)
		return (T_TRUNC);
	if (strncmp(str, ">>", 2) == 0)
		return (T_APPEND);
	if (strncmp(str, "<", 1) == 0)
		return (T_INPUT);
	if (strncmp(str, "|", 1) == 0)
		return (T_PIPE);
	return (T_CMD);
}

void    insert_node_token(t_token **root, char *command)
{
    t_token *new_node;
	t_token *curr;
	int	type;

	type = return_type(command);
    new_node = malloc(sizeof(t_token));
    if (!new_node)
        exit(1);
    new_node->command = command;
    new_node->path = NULL;
    new_node->argument = NULL;
    new_node->operator = NULL;
    new_node->file = NULL;
    new_node->type = type;
    new_node->fd = 0;

    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}
//noter les type de chaque command (T_CMD, T_EMPTY/T_END  T_CMD  T_TRUNC  T_APPEND  T_INPUT)
/*Dans une commande shell, un signe de redirection est généralement suivi par le nom du fichier ou le descripteur de fichier avec lequel il doit interagir. Par exemple :
Dans command > file.txt, le signe > redirige la sortie de command vers file.txt.
Dans command < file.txt, le signe < fait que command lit son entrée à partir de file.txt.
Dans command1 | command2, le signe | pipe la sortie de command1 à l'entrée de command2.
Donc, dans votre fonction parse_token, lorsque vous rencontrez un signe de redirection, vous devriez généralement traiter le prochain élément dans str comme l'argument de la redirection.*/

void    parse_token(t_token **token, char **str)
{
    int i;
	t_token *curr;
	char tmp;

    i = 0;
	curr = *token;
	(*token)->command = str[i++];
	(*token)->type = T_CMD;
	tmp = (*token)->command[0];
    while (str[i] != NULL)
    {
		if (strncmp(str[i] , ">>", 2) == 0)
			heredoc(*token);
		if (tmp != '|')
			curr->argument = str[i++];
		if (str[i] == NULL)
			break;
		insert_node_token(token, str[i]);
		curr = curr->next;
		tmp = curr->command[0];
		i++;

    }
}

// int main()
// {
//     t_token *root;
//     t_token *curr;

//     root = init_token_struct();
//     parse_token(&root, str)
//     curr = root;
//     while (curr != NULL)
//     {
//         printf("key : %s\n", curr->command);
//         printf("value : %s\n", curr->argument);
//         curr = curr->next;
//     }
// }