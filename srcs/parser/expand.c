/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:03:17 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 18:03:23 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "termios.h"

/*
 * have 3 type of expand
 * - expand
 *   - $[alphabet or underscore]
 * - not expand
 *   - $[number or other character not alphabet and underscore]
 * - and $ is gone ????
 *   - out single quote and double quote and after $ have " or '
*/
bool	check_expand(t_token *token)
{
	int		i;

	if (token->type != CMD)
		return (false);
	init_check_double_quote();
	init_check_quote();
	i = 0;
	while (token->word[i])
	{
		check_quote(token->word[i]);
		if (check_double_quote(token->word[i]) && token->word[i] == '$')
		{
			if (token->word[i + 1] && (ft_isalpha(token->word[i + 1]) \
|| token->word[i + 1] == '_' || token->word[i + 1] == '$' \
|| token->word[i + 1] == '?'))
				return (true);
			if (check_quote(token->word[i]) && (token->word[i + 1] == '\'' 
				|| token->word[i + 1] == '"'))
				return (true);
		}
		i++;
	}
	return (false);
}

void	expand_this_node(t_list *node)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	str = ((t_token *)node->content)->word;
	while (str[i])
	{
		i++;
	}
}

void	expand(t_list *token)
{
	while (token)
	{
		if (check_expand(token->content))
			expand_line(&((t_token *)token->content)->word);
		token = token->next;
	}
}
