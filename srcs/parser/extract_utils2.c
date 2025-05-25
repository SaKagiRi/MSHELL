/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/02 13:14:36 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	valid_pipe(char *start, char *line)
{
	char	*prev;
	char	*next;

	prev = start - 1;
	while (prev >= line && ft_isspace(*prev))
		prev--;
	if (prev < line || *prev == '|')
	{
		printf("syntax error near '|'\n");
		exit(1);
	}
	next = start + 1;
	while (*next && ft_isspace(*next))
		next++;
	if (*next == '\0' || *next == '|')
	{
		printf("syntax error near '|'\n");
		exit(1);
	}
}

bool	syntax_check(char *line)
{
	int		valid_single;
	int		valid_double;
	char	*start;

	valid_double = 0;
	valid_single = 0;
	start = line;
	while (*start)
	{
		if (*start == '|'
			&& valid_double == 0
			&& valid_single == 0)
			valid_pipe(start, line);
		if (*start == '\''
			&& valid_double == 0)
			valid_single = !valid_single;
		else if (*start == '\"'
			&& valid_single == 0)
			valid_double = !valid_double;
		start++;
	}
	if (valid_double == 1
		|| valid_single == 1)
	{
		printf("syntax error\n");
		return (false);
	}
	return (true);
}

int	word_len(char *start)
{
	char	*end;

	end = start;
	while (*end && !ft_isspace(*end)
		&& !ft_isoperator(end))
		end++;
	return (end - start);
}

int	word_len_inquote(char *start, t_word_type type)
{
	char 	*end;
	int		word_len;

	word_len = 0;
	end = start + 1;
	if (type == SINGLE_MATCH)
	{
		while (*end && *end != '\'')
			end++;
	}
	else if (type == DOUBLE_QUOTE)
	{
		while (*end && *end != '\"')
			end++;
	}
	word_len = end - start + 1;
	return (word_len);
}