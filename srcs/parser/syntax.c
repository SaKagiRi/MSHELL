/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:20:13 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 19:32:53 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * logic
 * - check is it pipe
 * - check before pipe is it cmd or invalid format
 * - check after pipe is it cmd or invalid format
 *
 * return value
 * - true mean valid pipe
 * - flase mean invalid pipe
*/
static bool	check_pipe(char *line, int point)
{
	int		i;

	if (line[point] != '|')
		return (true);
	i = point;
	while (line[--i])
	{
		if (line[i] == '|')
			return (false);
		else if (!ft_isspace(line[i]))
			break ;
	}
	if (!line[i])
		return (false);
	i = point;
	while (line[++i])
	{
		if (line[i] == '|' || !line[i])
			return (false);
		else if (!ft_isspace(line[i]))
			return (true);
	}
	return (false);
}

/*
 * logic
 * - check is it duble redirect if true move point to next 
 *   char (last operator redirect)
 * - chack after operation is it other operation, for return false
 * - check is it not isspace return true
 * - but if out loop mean not have value in redirect return false
 *
 * return value
 * - true mean valid redirect
 * - false mean invalid redirect
*/
static bool	check_redirect(char *line, int *point)
{
	int		i;

	if (!ft_strncmp(&line[*point], ">>", 2) \
|| !ft_strncmp(&line[*point], "<<", 2))
		*point += 1;
	else if (!(line[*point] == '>' || line[*point] == '<'))
		return (true);
	i = *point;
	while (line[++i])
	{
		if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			return (false);
		else if (!ft_isspace(line[i]))
			return (true);
	}
	return (false);
}

bool	syntax(char *line)
{
	int		i;
	bool	s_q;
	bool	d_q;

	i = -1;
	s_q = false;
	d_q = false;
	while (line[++i])
	{
		if (line[i] == '\'' && !d_q)
			s_q = !s_q;
		else if (line[i] == '\"' && !s_q)
			d_q = !d_q;
		if (!d_q && !s_q && (!check_pipe(line, i) || !check_redirect(line, &i)))
		{
			pnf_fd(2, "bash: syntax error\n");
			return (false);
		}
	}
	if (s_q || d_q)
	{
		pnf_fd(2, "bash: syntax error\n");
		return (false);
	}
	return (true);
}
