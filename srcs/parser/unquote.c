/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:45:23 by knakto            #+#    #+#             */
/*   Updated: 2025/05/29 09:21:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	init(t_token *token, char **res)
{
	*res = malloc(sizeof(char) * ft_strlen(token->word));
	if (!*res)
		return (true);
	return (false);
}

static void	unquote_all(t_token *token)
{
	char	*res;
	int		i;
	int		j;
	bool	d_q;
	bool	s_q;

	if (init(token, &res))
		return ;
	i = -1;
	j = 0;
	d_q = false;
	s_q = false;
	while (token->word[++i])
	{
		if (token->word[i] == '\'' && !d_q)
			s_q = !s_q;
		else if (token->word[i] == '"' && !s_q)
			d_q = !d_q;
		else
			res[j++] = token->word[i];
	}
	while (j < i)
		res[j++] = '\0';
	free(token->word);
	token->word = res;
}

void	unquote(t_list **token)
{
	t_list	*node;

	node = *token;
	while (node)
	{
		if (ft_strchr(((t_token *)node->content)->word, '"') \
|| ft_strchr(((t_token *)node->content)->word, '\''))
			unquote_all(node->content);
		node = node->next;
	}
}
