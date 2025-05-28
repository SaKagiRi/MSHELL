/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:43:14 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 15:48:33 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	delete_space_null_value(t_list **token)
{
	char	*str;
	t_list	*before;
	t_list	*node;
	t_list	*temp;

	if (((t_token *)(*token)->content)->word[0] == '\0')
	{
		temp = *token;
		*token = (*token)->next;
		ft_lstdelone(temp, clear_token);
	}
	node = (*token)->next;
	before = *token;
	while (node)
	{
		if (((t_token *)node->content)->word[0] == '\0')
		{
			temp = node;
			node = node->next;
			before->next = node;
			ft_lstdelone(temp, clear_token);
		}
		before = node;
		node = node->next;
	}
}

/*
 * logic
 * - split [<] and [>] and append type redirect and if it find [>>] or [<<]
 * its will split like [>] [] [>] or [<] [] [<] and I fixed 
 * it just delete it lol.
 * - and after that all redirect will type REDIRECT I just add type to it
*/
void	split_redirect(t_list **token)
{
	split_one_redirect(token);
	split_one_redirect(token);
	delete_space_null_value(token);
	append_redirect_type(token);
	append_redirect_value_type(token);
}
