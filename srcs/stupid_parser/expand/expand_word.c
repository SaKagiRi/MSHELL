/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:00:45 by knakto            #+#    #+#             */
/*   Updated: 2025/05/07 14:34:27 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

int	len_expand(char *line)
{
	int		i;

	i = 0;
	if (!is_expand(line))
		return (0);
	if (line[1] == '\'' || line[1] == '"')
		return (1);
	if (line[1] == '$' || line[1] == '?')
		return (2);
	while (line[i])
	{
		if (!(i == 0 || i == 1))
		{
			if (!(ft_isalpha(line[i]) || ft_isalpha(line[i]) || line[i] == '-'))
				return (i);
		}
		i++;
	}
	return (i);
}

void	add_word(char *line, int point, int len)
{
	t_word	*word;
	t_word	*temp;

	if (!get_t_word() || len == 0)
		return ;
	if (len == -1)
		len = INT_MAX;
	temp = malloc(sizeof(t_word));
	if (!temp)
		return ;
	if (*get_t_word() == NULL)
	{
		temp->word = ft_substr(line, point, len);
		temp->expand = NULL;
		temp->next = NULL;
		*get_t_word() = temp;
		return ;
	}
	word = *get_t_word();
	while (word->next)
		word = word->next;
	temp->word = ft_substr(line, point, len);
	temp->expand = NULL;
	temp->next = NULL;
	word->next = temp;
}

void	use_expand(void)
{
	t_word	*word;
	bool	d_q;
	bool	s_q;
	int		i;

	word = *get_t_word();
	d_q = false;
	s_q = false;
	while (word)
	{
		i = 0;
		while (word->word[i])
		{
			if (word->word[i] == '\'' && !d_q)
				s_q = !s_q;
			if (word->word[i] == '"' && !s_q)
				d_q = !d_q;
			i++;
		}
		if (word->word[0] == '$' && !s_q)
			word->expand = get_value(&word->word[1]);
		word = word->next;
	}
}

void	expand_word(char *line)
{
	int		before;
	int		i;

	i = 0;
	before = 0;
	while (line[i])
	{
		if (is_expand(&line[i]))
		{
			add_word(line, before, i - before);
			before = i;
			i += len_expand(&line[i]);
			if (!line[i])
				break ;
			add_word(line, before, i - before);
			before = i;
		}
		else if (is_in_s_quote(line[i]) && !ft_strchr(&line[i], '$'))
			add_word(line, before, -1);
		i++;
	}
	if (i - before > 1)
		add_word(line, before, -1);
	use_expand();
}
