/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:08:31 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 19:34:58 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	sub_fnc_split_token(t_list **node, char *str, int *i, int *start)
{
	ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(str, \
*start, *i - *start), CMD)));
	*start = *i + 1;
	ft_lstadd_back(node, ft_lstnew(new_token(ft_strdup("|"), PIPE)));
}

static bool	sub_fnc_start_or_end(int type, int *i, char *str, t_list **node)
{
	if (type == START)
	{
		if (str[0] == '|')
		{
			ft_lstadd_back(node, ft_lstnew(new_token(ft_strdup("|"), PIPE)));
			*i += 1;
		}
		return (true);
	}
	else if (type == END)
	{
		if (str[ft_strlen(str) - 1] == '|')
		{
			pnf("yes\n");
			ft_lstadd_back(node, ft_lstnew(new_token(ft_substr(str, \
*i, (ft_strlen(str) - 1) - *i), CMD)));
			ft_lstadd_back(node, ft_lstnew(new_token(ft_strdup("|"), PIPE)));
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
		if (check_quote(str[i]) && str[i] == '|' \
&& i != 0 && i != ft_strlen(str) - 1)
			sub_fnc_split_token(&node, str, &i, &start);
		i++;
	}
	i = start;
	if (sub_fnc_start_or_end(END, &i, str, &node) && str[start])
		ft_lstadd_back(&node, ft_lstnew(new_token(ft_strdup(\
&str[start]), CMD)));
	ft_lstadd_back(&node, token->next);
	return (node);
}

void	append_pipe_type(t_list **token)
{
	t_list	*node;

	node = *token;
	while (node)
	{
		if (((t_token *)node->content)->word[0] == '|' \
&& ft_strlen(((t_token *)node->content)->word))
			((t_token *)node->content)->type = PIPE;
		else
			((t_token *)node->content)->type = CMD;
		node = node->next;
	}
}

/*
 * logic
 * - check each linked list its have pipe in this node
 *   - first if use for [start node]
 * - while run all node and check 
 *   -[have pipe in that node] 
 *   -[this node will not replace or not have type before]
 *   -[and its must have 3 or more charactor for protect only pipe]
 * - after sent that node to function will get new linked list it split pipe
 * - will move before for change node and delete
*/
void	split_pipe(t_list **token)
{
	t_list	*temp;
	t_list	*before;
	t_list	*node;

	if (ft_strchr(((t_token *)(*token)->content)->word, '|'))
	{
		temp = *token;
		*token = split_token(*token);
		ft_lstdelone(temp, clear_token);
	}
	node = (*token)->next;
	before = *token;
	while (node)
	{
		if (ft_strchr(((t_token *)node->content)->word, '|') && ((t_token *)node->\
content)->type != PIPE && ft_strlen(((t_token *)node->content)->word) >= 3)
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
