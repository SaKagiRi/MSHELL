/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:48:44 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 02:32:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static int	correct_redirect(char *line)
{
	int		i;
	int		len;

	if (!line || !line[0])
		return (-1);
	len = 1;
	if (!ft_strncmp(line, ">>", 2) || !ft_strncmp(line, "<<", 2))
		len = 2;
	if (!line[len])
		return (-1);
	i = len;
	while (line[i])
	{
		if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			return (-1);
		if (!ft_isspace(line[i]))
			return (len - 1);
		i++;
	}
	return (-1);
}

bool	check_redirect(char *line)
{
	int		i;
	int		r;
	bool	s_q;
	bool	d_q;

	i = 0;
	s_q = false;
	d_q = false;
	while (line[i])
	{
		r = 0;
		if (line[i] == '\'')
			s_q = !s_q;
		else if (line[i] == '"')
			d_q = !d_q;
		else if (!d_q && !s_q && (line[i] == '>' || line[i] == '<'))
			r = correct_redirect(&line[i]);
		if (r == -1)
			return (0);
		i += r;
		i++;
	}
	return (1);
}
