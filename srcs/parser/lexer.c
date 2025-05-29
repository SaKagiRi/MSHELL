/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:57:03 by knakto            #+#    #+#             */
/*   Updated: 2025/05/29 09:28:36 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#if DEBUG_PARSER==1

static void	print_type(t_token *token);

void	print_word(t_list *token)
{
	while (token)
	{
		pnf("token:[%s]\n", ((t_token *)token->content)->word);
		print_type(token->content);
		token = token->next;
	}
}

#else

void	print_word(t_list *token)
{
}

#endif

static void	print_type(t_token *token)
{
	if (token->type == READ_FILE)
		pnf("type: [READ]\n");
	else if (token->type == WRITE_FILE)
		pnf("type: [WRITE]\n");
	else if (token->type == WORD)
		pnf("type: [WORD]\n");
	else if (token->type == APPEND_FILE)
		pnf("type: [APPEND]\n");
	else if (token->type == HERE_DOC)
		pnf("type: [HEREDOC]\n");
	else if (token->type == CMD)
		pnf("type: [CMD]\n");
	else if (token->type == VALUE_REDIRECT)
		pnf("type: [VALUE]\n");
	else if (token->type == PIPE)
		pnf("type: [PIPE]\n");
	else
		pnf("type: [NONE]\n");
}

void	clear_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	free(t->word);
	free(token);
}

/*
 * logic
 * - split spcace to token word
 * - TODO: split some word have $ | > < >> << and not in quote to operator
*/
void	lexer(t_list **token, char *line)
{
	split_space(token, line);
	split_pipe(token);
	append_pipe_type(token);
	split_redirect(token);
}
