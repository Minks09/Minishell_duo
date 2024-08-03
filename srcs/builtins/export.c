/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:14:18 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/03 15:43:28 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*return_value_quoted(char *str)
{
	int		size;
	char	*tmp;
	char	*value;

	if (!str)
		return (NULL);
	tmp = strchr(str, '=');
	tmp++;
	tmp++;
	value = strdup(tmp);
	size = strlen(value);
	value[size - 1] = '\0';
	return (value);
}

int	export(t_envp **root, char *new_var)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (new_var[i] != '=')
		i++;
	if (new_var[++i] == '\"')
		value = return_value_quoted(new_var);
	else
		value = return_value(new_var);
	key = return_key(new_var);
	insert_node_env(root, key, value);
	return (SUCCESS);
}
