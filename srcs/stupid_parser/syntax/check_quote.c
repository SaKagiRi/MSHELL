/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:00:45 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 02:12:07 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static bool	s_quote(int c)
{
	if (c == 39)
		return (1);
	return (0);
}

static bool	d_quote(int c)
{
	if (c == '"')
		return (1);
	return (0);
}

bool	check_quote(char *line)
{
	bool	s_q;
	bool	d_q;
	bool	status;
	int		i;

	s_q = false;
	d_q = false;
	status = false;
	i = 0;
	while (line[i] && !status)
	{
		if (s_quote(line[i]) && !d_q)
			s_q = !s_q;
		else if (d_quote(line[i]) && !s_q)
			d_q = !d_q;
		else if (line[i] == '|' && !s_q && !d_q)
			status = !check_pipe(line, i);
		i++;
	}
	status = s_q || d_q || status;
	if (status)
		return (0);
	return (1);
}
