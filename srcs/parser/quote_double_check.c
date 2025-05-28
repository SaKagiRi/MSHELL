/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_double_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:44:45 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 16:12:23 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	*get_d_q(void)
{
	static bool	d_q;

	return (&d_q);
}

static bool	*get_s_q(void)
{
	static bool	s_q;

	return (&s_q);
}

void	init_check_double_quote(void)
{
	*get_s_q() = false;
	*get_d_q() = false;
}

bool	check_double_quote(char c)
{
	bool	s_q;
	bool	d_q;

	s_q = *get_s_q();
	d_q = *get_d_q();
	if (c == '\'' && !d_q)
		s_q = !s_q;
	else if (c == '"' && !s_q)
		d_q = !d_q;
	*get_s_q() = s_q;
	*get_d_q() = d_q;
	return (!s_q);
}
