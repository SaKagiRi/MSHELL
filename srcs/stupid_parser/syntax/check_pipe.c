/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:11:12 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 01:13:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static bool	loop_check(char *line, int i, int mode)
{
	bool	status;

	status = true;
	while (line[i] && status)
	{
		if (!ft_isspace(line[i]))
		{
			if (line[i] == '|')
				return (false);
			status = false;
		}
		if (mode == 0)
			i--;
		else if (mode == 1)
			i++;
	}
	return (status);
}

bool	check_pipe(char *line, int len)
{
	int		i;
	int		mode;
	bool	status;

	if (!line || !line[len])
		return (1);
	mode = 0;
	while (mode < 2)
	{
		i = len - 1;
		if (mode == 1)
			i = len + 1;
		if (len < 0)
			return (false);
		status = loop_check(line, i, mode);
		if (status)
			return (false);
		mode++;
	}
	return (true);
}
