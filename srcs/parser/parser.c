/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:10:01 by knakto            #+#    #+#             */
/*   Updated: 2025/05/26 19:50:07 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

bool	parser(char *line)
{
	t_list	*token;

	if (line_is_null(line) || !syntax(line))
		return (false);
	token = NULL;
	lexer(&token, line);
	return (true);
}
