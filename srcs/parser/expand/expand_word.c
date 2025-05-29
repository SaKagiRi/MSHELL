/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:00:45 by knakto            #+#    #+#             */
/*   Updated: 2025/05/29 11:46:26 by knakto           ###   ########.fr       */
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
			if (!(ft_isalnum(line[i]) || ft_isalpha(line[i]) || line[i] == '_'))
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
	int		i;

	word = *get_t_word();
	init_check_double_quote();
	while (word)
	{
		i = -1;
		while (word->word[++i])
			check_double_quote(word->word[i]);
		if (word->word[0] == '$' && check_double_quote(word->word[0]) \
&& word->word[1] && word->word[1] != '\'' && word->word[1] != '"')
			word->expand = get_value(&word->word[1]);
		word = word->next;
	}
}

static bool	sub_fnc_expand(char *line, int *before, int *i)
{
	add_word(line, *before, *i - *before);
	*before = *i;
	*i += len_expand(&line[*i]);
	if (!line[*i])
		return (false);
	add_word(line, *before, *i - *before);
	*before = *i;
	return (true);
}

/*
 * logic
 * - while loop string if find $ must len use "alnum alpha and _"
 * and split all with "sub_fnc_expand" it use for add word before expand
 * add word expand($) and check have any word after expand? if have
 * just add more word after that
 * - two facter if dont have any $ must copy all line
 * - and copy again??, but it fine just work I dont wanna tuch it
 * I have idea to do this long time ago.
 * - use_expand have for change word $A to A and after all expland_line
 * just use join line to join none expand and expand
*/
void	expand_word(char *line)
{
	int		before;
	int		i;

	i = -1;
	before = 0;
	while (line[++i])
	{
		if (is_expand(&line[i]))
			if (!sub_fnc_expand(line, &before, &i))
				break ;
		if (is_in_s_quote(line[i]) && !ft_strchr(&line[i], '$'))
			add_word(line, before, -1);
	}
	sub_fnc_expand(line, &before, &i);
	use_expand();
}
