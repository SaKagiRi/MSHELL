/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:10:01 by knakto            #+#    #+#             */
/*   Updated: 2025/06/03 01:10:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "process.h"

static	bool	line_is_null(char *line)
{
	char	*str;

	str = ft_strtrim(line, " \t\n");
	if (!*str)
	{
		free(str);
		return (true);
	}
	free(str);
	return (false);
}

static int	len_command(t_list *node)
{
	int			i;
	t_token		*token;

	i = 0;
	while (node)
	{
		token = node->content;
		if (token->type == PIPE)
			break ;
		else if (token->type == CMD)
			i++;
		node = node->next;
	}
	return (i);
}

bool	sub_fnc(t_list *token, t_redirect **re, char **arg, int *i)
{
	if (((t_token *)token->content)->type == CMD)
	{
		arg[*i] = ft_strdup(((t_token *)token->content)->word);
		*i += 1;
	}
	else if (token->next \
&& ((t_token *)token->next->content)->type == VALUE_REDIRECT)
		addback_re(re, token->content, token->next->content);
	if (((t_token *)token->content)->type == PIPE)
	{
		arg[*i] = NULL;
		addback_proc(arg, *re);
		return (true);
	}
	return (false);
}

static void	parser_to_execution(t_list *token)
{
	t_redirect	*re;
	bool		start_cmd;
	char		**arg;
	int			i;

	start_cmd = true;
	while (token)
	{
		if (start_cmd)
		{
			start_cmd = false;
			re = NULL;
			arg = malloc(sizeof(char *) * (len_command(token) + 1));
			if (!arg)
				return ;
			i = 0;
		}
		if (sub_fnc(token, &re, arg, &i))
			start_cmd = true;
		token = token->next;
	}
	arg[i] = NULL;
	addback_proc(arg, re);
}

bool	parser(char *line)
{
	t_list	*token;

	if (line_is_null(line) || !syntax(line))
		return (false);
	token = NULL;
	lexer(&token, line);
	expand(token);
	unquote(&token);
	print_word(token);
	parser_to_execution(token);
	ft_lstclear(&token, clear_token);
	print_proc();
	free(line);
	return (true);
}
