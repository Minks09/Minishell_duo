/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:59:35 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/03 15:14:31 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*init_token_struct(void)
{
	t_token	*token;

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

void	free_token_struct(t_token **token)
{
	t_token	*curr;
	t_token	*tmp;

	curr = *token;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->command);
		tmp->command = NULL;
		free(tmp->path);
		tmp->path = NULL;
		free(tmp->argument);
		tmp->argument = NULL;
		free(tmp->operator);
		tmp->operator = NULL;
		free(tmp->file);
		tmp->file = NULL;
		free(tmp);
		tmp = NULL;
	}
	*token = NULL;
}

void	insert_node_token(t_token **root, char *command)
{
	t_token	*new_node;
	t_token	*curr;
	int		type;

	type = return_type(command);
	new_node = malloc(sizeof(t_token));
	if (!new_node)
		exit(1);
	new_node->command = strdup(command);
	new_node->path = NULL;
	new_node->argument = NULL;
	new_node->operator = NULL;
	new_node->file = NULL;
	new_node->type = type;
	new_node->fd = 0;
	new_node->next = NULL;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	parse_token(t_token **token, char **str)
{
	int		i;
	t_token	*curr;
	char	tmp;

	i = 0;
	curr = *token;
	(*token)->command = strdup(str[i]);
	(*token)->type = T_CMD;
	tmp = (*token)->command[0];
	while (str[++i] != NULL)
	{
		if (check_redirection(str[i - 1], str[i]) != 0)
			curr->fd = check_redirection(str[i - 1], str[i]);
		while (tmp != '|' && str[i])
		{
			if (str[i][0] == '|' || str[i][0] == '<' || str[i][0] == '>')
				break ;
			curr->argument = join_argument(curr->argument, str[i++]);
		}
		if (str[i] == NULL)
			break ;
		insert_node_token(token, str[i]);
		curr = curr->next;
		tmp = curr->command[0];
	}
}

char	*join_argument(char *argument, char *str)
{
	int		i;
	int		j;
	int		lenght;
	char	*new_argument;

	i = -1;
	j = -1;
	if (!argument)
		argument = strdup("");
	lenght = strlen(argument) + strlen(str) + 1;
	new_argument = malloc(sizeof(char) * (lenght + 1));
	if (!new_argument)
		return (NULL);
	while (argument[++i] != '\0')
		new_argument[i] = argument[i];
	if (argument[i] != '\0')
		new_argument[i++] = ' ';
	while (str[++j] != '\0')
		new_argument[i + j] = str[j];
	new_argument[i + j] = '\0';
	free(argument);
	argument = NULL;
	return (new_argument);
}

// int main()
// {
//     t_token *root;
//     t_token *curr;

//     root = init_token_struct();
//     parse_token(&root, str);
//     curr = root;
//     while (curr != NULL)
//     {
//         printf("key : %s\n", curr->command);
//         printf("value : %s\n", curr->argument);
//         curr = curr->next;
//     }
// }