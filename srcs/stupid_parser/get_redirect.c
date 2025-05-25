/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:40 by knakto            #+#    #+#             */
/*   Updated: 2025/05/07 15:45:25 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_parser.h"

static t_redirect_type	get_type_redirect(char *s)
{
	if (!ft_strncmp(s, ">", 1))
		return (WRITE_FILE);
	else if (!ft_strncmp(s, "<", 1))
		return (READ_FILE);
	else if (!ft_strncmp(s, ">>", 2))
		return (APPEND_FILE);
	else if (!ft_strncmp(s, "<<", 2))
		return (HERE_DOC);
	return (-1);
}

static char	*get_redirect(t_redirect_type type)
{
	if (type == WRITE_FILE)
		return (">");
	else if (type == READ_FILE)
		return ("<");
	else if (type == APPEND_FILE)
		return (">>");
	else if (type == HERE_DOC)
		return ("<<");
	return ("");
}

int	is_redirect(char *s)
{
	if (!ft_strncmp(s, ">", 1) || !ft_strncmp(s, "<", 1))
	{
		if (ft_strlen(s) == 1)
			return (1);
		return (2);
	}
	else if (!ft_strncmp(s, ">>", 2) || !ft_strncmp(s, ">>", 2))
	{
		if (ft_strlen(s) == 2)
			return (1);
		return (2);
	}
	return (0);
}
