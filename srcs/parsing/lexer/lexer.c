/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigateau <nigateau@student.42.lausanne>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:22:20 by nigateau          #+#    #+#             */
/*   Updated: 2024/08/01 22:33:16 by nigateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

t_bool	check_both_quotes(char *input)
{
	int	squotes_count;
	int dquotes_count;
	int	i;

	i = 0;
	squotes_count = 0;
	dquotes_count = 0;
	while(input[i])
	{
		if(input[i] == '\'')
			squotes_count++;
		if(input[i] == '\"')
			dquotes_count++;
		i++;
	}
	if((squotes_count % 2) || (dquotes_count % 2))
		return (FALSE);
	return (TRUE);
}

void	escape_single_quote(char *input)
{
	int i;
	int	len;
	
	i = 0;
	len = strlen(input);
	while (input[i] != '\'' && input[i] != '\0')
			i++;
	if (input[i] == '\0')
		return;
	i++;
	while (input[i])
	{
		if (input[i] == '[' || input[i] == ']' || input[i] == '\\' || input[i] == '^'
		|| input[i] == '.' || input[i] == '|' || input[i] == '?' || input[i] == '*'
		|| input[i] == '+' || input[i] == '-' || input[i] == '{'|| input[i] == '}'
		|| input[i] == '(' || input[i] == ')' || input[i] == '$')
		{
			memmove(&input[i + 1], &input[i], len - i + 1);
			input[i++] = '\\';
			len++;
		}
		if (input[i] == '\'')
			break;
		i++;
	}
}

void	escape_double_quote(char *input)
{
	int i;
	int	len;
	
	i = 0;
	len = strlen(input);
	while (input[i] != '\"' && input[i] != '\0')
			i++;
	if (input[i] == '\0')
		return;
	i++;
	while (input[i])
	{
		if (input[i] == '[' || input[i] == ']' || input[i] == '\\' || input[i] == '^'
		|| input[i] == '.' || input[i] == '|' || input[i] == '?' || input[i] == '*'
		|| input[i] == '+' || input[i] == '-' || input[i] == '{'|| input[i] == '}'
		|| input[i] == '(' || input[i] == ')')
		{
			memmove(&input[i + 1], &input[i], len - i + 1);
			input[i++] = '\\';
			len++;
		}
		if (input[i] == '\"')
			break;
		i++;
	}
}
t_bool	search_semi_back(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\"')
				i++;
		}
		if (str[i] == ';' || str[i] == '\\')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// char	*expand(char *str)
// {
// 	int	i;
// 	char *temp;
// 	char *var;

// 	i = 0;
// 	if (str[i] == '$')
// 		str++;
// 	temp = getenv(str);
// 	if (temp == NULL)
// 		perror("variable not found");
// 	var = strdup(temp);
// 	return (var);
// }

// int main(void)
// {
// 	char *str;

// 	str = strdup("je suis * 'un mendiant *' bonjour");
// 	escape_single_quote(str);
// 	printf("%s\n", str);
// 	return (0);
// }
