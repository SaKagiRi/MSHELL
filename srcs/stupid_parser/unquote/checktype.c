/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:57:02 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:14:48 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../s_parser.h"

t_type	check_type(char *line)
{
	if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1))
		return (T_REDIRECT);
	else if (!ft_strncmp(line, "|", 1))
		return (T_PIPE);
	else if (!ft_strncmp(line, "<<", 2) || !ft_strncmp(line, ">>", 2))
		return (T_REDIRECT);
	return (T_CMD);
}

t_type	check_type_redirect(char *s1, char *s2)
{
	if (*s1 == '<')
	{
		if (*s2 == '<')
			return (T_HEREDOC);
		else
			return (T_READ);
	}
	if (*s1 == '>')
	{
		if (*s2 == '>')
			return (T_APPEND);
		else
			return (T_WRITE);
	}
	return (T_CMD);
}
