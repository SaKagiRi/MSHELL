/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:44:41 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 10:52:24 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

bool	is_in_s_quote(char c)
{
	static bool	s_q = false;
	static bool	d_q = false;

	if (c == '\'' && !d_q)
		s_q = !s_q;
	else if (c == '"' && !s_q)
		d_q = !d_q;
	if (s_q)
		return (true);
	return (false);
}

bool	is_expand(char *line)
{
	if (!is_in_s_quote(line[0]) && line[0] == '$' && (ft_isalpha(line[1]) \
|| line[1] == '\'' || line[1] == '"' || line[1] == '$' || line[1] == '_' || \
line[1] == '?'))
		return (true);
	return (false);
}
