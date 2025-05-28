/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:38:55 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 15:41:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "process.h"

/*
 * input
 * - node of linklist for checktype this is what redirect
 * return
 * - type of redirect and if not return CMD
*/
static int	typeof_re(t_list *token)
{
	t_token	*t;
	t_token	*next_t;

	t = token->content;
	if (t->type != REDIRECT)
		return (CMD);
	else if (ft_strlen(t->word) == 1 && t->word[0] == '<')
	{
		next_t = token->next->content;
		if (((t_token *)token->next->content)->word[0] == '<')
			return (HERE_DOC);
		else
			return (READ_FILE);
	}
	else if (ft_strlen(t->word) == 1 && t->word[0] == '>')
	{
		next_t = token->next->content;
		if (((t_token *)token->next->content)->word[0] == '>')
			return (APPEND_FILE);
		else
			return (WRITE_FILE);
	}
	return (CMD);
}

/*
 * return
 * - redirect type for strdup
*/
static char	*str_type(t_token *token)
{
	if (token->type == HERE_DOC)
		return ("<<");
	else if (token->type == APPEND_FILE)
		return (">>");
	return ("");
}

/*
 * use this if find [<] [<] or [>] [>] to change to [<<] [>>]
 *
 * logic
 * - addtype to type
 * - move next node
 * - change word to [<<] or [>>]
 * - delete 2rd node
*/
static void	found_big_redirect(t_list *node)
{
	t_list	*temp;

	temp = node->next;
	((t_token *)node->content)->type = typeof_re(node);
	node->next = node->next->next;
	free(((t_token *)node->content)->word);
	((t_token *)node->content)->word = ft_strdup(str_type(node->content));
	ft_lstdelone(temp, clear_token);
}

void	append_redirect_value_type(t_list **token)
{
	t_list	*node;
	t_list	*before;
	int		type;

	node = (*token)->next;
	before = *token;
	while (node)
	{
		type = ((t_token *)before->content)->type;
		if (type == READ_FILE || type == WRITE_FILE || type == APPEND_FILE \
|| type == HERE_DOC)
			((t_token *)node->content)->type = VALUE_REDIRECT;
		before = node;
		node = node->next;
	}
}

/*
 * function to check redirect type and append it
 * and if found [>] [>] or [<] [<] will auto change to [>>], [<<]
*/
void	append_redirect_type(t_list **token)
{
	t_list	*node;

	node = *token;
	while (node)
	{
		if (typeof_re(node) == HERE_DOC || typeof_re(node) == APPEND_FILE)
			found_big_redirect(node);
		else if (((t_token *)node->content)->word[0] == '>')
			((t_token *)node->content)->type = WRITE_FILE;
		else if (((t_token *)node->content)->word[0] == '<')
			((t_token *)node->content)->type = READ_FILE;
		node = node->next;
	}
}
