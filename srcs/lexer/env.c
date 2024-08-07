/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:29:10 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/03 15:23:05 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	insert_node_env(t_envp **root, char *key, char *value)
{
	t_envp	*new_node;
	t_envp	*curr;

	new_node = malloc(sizeof(t_envp));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->key = key;
	new_node->value = value;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	remove_node_env(t_envp **root, char *key)
{
	t_envp	*curr;
	t_envp	*to_remove;

	curr = *root;
	if (*root == NULL)
		return ;
	if (strcmp((*root)->key, key) == 0)
	{
		to_remove = *root;
		*root = (*root)->next;
		remove_node_env_extend(to_remove);
	}
	while (curr->next != NULL)
	{
		if (strcmp(curr->next->key, key) == 0)
		{
			to_remove = curr->next;
			curr->next = curr->next->next;
			remove_node_env_extend(to_remove);
		}
		curr = curr->next;
	}
}

void	free_env(t_envp **root)
{
	t_envp	*curr;
	t_envp	*tmp;

	curr = *root;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->key);
		tmp->key = NULL;
		free(tmp->value);
		tmp->value = NULL;
		free(tmp);
		tmp = NULL;
	}
	*root = NULL;
}

t_envp	*return_env(t_shell *shell, char **env)
{
	t_envp	*root;
	int		i;

	i = 1;
	shell->env_tab = return_env_tab(env);
	root = malloc(sizeof(t_envp));
	if (!root)
		return (NULL);
	root->key = return_key(env[0]);
	root->value = return_value(env[0]);
	root->next = NULL;
	while (env[i])
	{
		insert_node_env(&root, return_key(env[i]), return_value(env[i]));
		i++;
	}
	return (root);
}

char	**return_env_tab(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env[i] = strdup(envp[i]);
		if (!env[i])
		{
			// Libére la mémoire allouée précédemment en cas d'échec
			while (i > 0)
			{
				free(env[--i]);
			}
			free(env);
			return (NULL);
		}
		i++;
	}
	env[i] = NULL;
	return (env);
}

// int main(int argc, char **argv, char **env)
// {
//     int     i;
//     t_envp  *root;
//     t_envp  *curr;
//     char    *new_var;

//     i = 1;
//     new_var = strdup("POULET=ambition");
//     root = malloc(sizeof(t_envp));
//     if (!root)
//         exit(1);
//     root->key = return_key(env[0]);
//     root->value = return_value(env[0]);
//     root->next = NULL;
//     while (env[i])
//     {
//         insert_node_env(&root, return_key(env[i]), return_value(env[i]));
//         i++;
//     }
//     export(&root, "POULET=\"ambition\"");
//     remove_node_env(&root, "LOGNAME");
//     curr = root;
//     while (curr != NULL)
//     {
//         printf("key : %s\n", curr->key);
//         printf("value : %s\n", curr->value);
//         curr = curr->next;
//     }
//     free_env(&root);
//     return (1);
// }

// int main(int argc, char **argv, char **envp)
// {
//     t_shell *shell;
//     t_envp *curr;
//
//     shell->env = return_env(shell, envp);
//     curr = shell->env;
//     while (curr != NULL)
//     {
//         printf("key : %s\n", curr->key);
//         printf("value : %s\n", curr->value);
//         curr = curr->next;
//     }
//     free_env(&shell->env);
//     free_tab(shell->env_tab);
//     return(1);
// }