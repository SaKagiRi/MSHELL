/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:39:23 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 16:55:38 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*new_token(char *word, int type)
{
	t_token	*token;

	if (!word)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->word = word;
	token->type = type;
	return (token);
}

static t_token	*get_word(int *i, char *line)
{
	int		point;
	bool	s_q;
	bool	d_q;

	while (ft_isspace(line[*i]))
		*i += 1;
	point = *i;
	s_q = false;
	d_q = false;
	while (line[*i])
	{
		if (line[*i] == '\'' && !d_q)
			s_q = !s_q;
		else if (line[*i] == '"' && !s_q)
			d_q = !d_q;
		else if (ft_isspace(line[*i]) && !s_q && !d_q)
			break ;
		*i += 1;
	}
	return (new_token(ft_substr(line, point, *i - point), WORD));
}

void	split_space(t_list **token, char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_strtrim(line, " \n\t");
	len = ft_strlen(str);
	while (i < len)
		ft_lstadd_back(token, ft_lstnew(get_word(&i, str)));
	free(str);
}
