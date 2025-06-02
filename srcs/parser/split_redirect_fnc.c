/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirect_fnc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:08:31 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 19:36:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	sub_fnc_split_token(t_list **node, char *str, int *i, int *start)
{
	ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(str, \
*start, *i - *start), CMD)));
	*start = *i + 1;
	ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(str, *i, 1), REDIRECT)));
}

static bool	sub_fnc_start_or_end(int type, int *i, char *str, t_list **node)
{
	if (type == START)
	{
		if (str[0] == '<' || str[0] == '>')
		{
			ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(\
str, *i, 1), REDIRECT)));
			*i += 1;
		}
		return (true);
	}
	else if (type == END)
	{
		if (str[ft_strlen(str) - 1] == '<' || str[ft_strlen(str) - 1] == '>')
		{
			ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(str, \
*i, (ft_strlen(str) - 1) - *i), CMD)));
			ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(\
str, ft_strlen(str) - 1, 1), REDIRECT)));
			return (false);
		}
		return (true);
	}
	return (false);
}

/*
 * logic
 * - check its have pipe in first character if true will append pipe 
and move index
 * - while check if pipe out quote will sub_str by start to pipe and append 
pipe and have one word not append
 * - check if have pipe in last character will add word before last pipe
and append pipe
 * - if not have pipe in last will append last word to cmd
 *
 * input
 * - node of linked list have pipe in side
 *
 * return
 * - new linked list splited with pipe
*/
static t_list	*split_token(t_list *token)
{
	t_list	*node;
	char	*str;
	int		start;
	int		i;

	node = NULL;
	i = 0;
	str = ((t_token *)token->content)->word;
	sub_fnc_start_or_end(START, &i, str, &node);
	init_check_quote();
	start = i;
	while (str[i])
	{
		if (check_quote(str[i]) && (str[i] == '>' || str[i] == '<') \
&& i != 0 && i != ft_strlen(str) - 1)
			sub_fnc_split_token(&node, str, &i, &start);
		i++;
	}
	i = start;
	if (sub_fnc_start_or_end(END, &i, str, &node) && str[start])
		ft_lstadd_back(&node, ft_lstnew(new_token(\
ft_strdup(&str[start]), CMD)));
	ft_lstadd_back(&node, token->next);
	return (node);
}

static bool	condition_check_redirect(t_token *token)
{
	if ((ft_strchr(token->word, '>') || ft_strchr(token->word, '<')) \
&& token->type != REDIRECT)
	{
		if ((ft_strnstr(token->word, ">>", 2) \
|| ft_strnstr(token->word, "<<", 2)) \
&& ft_strlen(token->word) >= 3)
			return (true);
		else if (ft_strlen(token->word) >= 2)
			return (true);
		return (false);
	}
	return (false);
}

/*
 * logic
 * - same of split pipe but split with [<] or [>] and if it have_redirect
 *   [<<] or [>>] it must split to [<] [] [<] or [>] [] [>] this is failed
 *   logic cause I am lazy but I can delete [] after this lol, Ez.
*/
void	split_one_redirect(t_list **token)
{
	t_list	*temp;
	t_list	*before;
	t_list	*node;

	if (condition_check_redirect((*token)->content))
	{
		temp = *token;
		*token = split_token(*token);
		ft_lstdelone(temp, clear_token);
	}
	node = (*token)->next;
	before = *token;
	while (node)
	{
		if (condition_check_redirect((node)->content))
		{
			temp = node;
			node = split_token(node);
			before->next = node;
			ft_lstdelone(temp, clear_token);
		}
		before = node;
		node = node->next;
	}
}
