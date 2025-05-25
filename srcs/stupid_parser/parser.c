/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:34:05 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 11:06:14 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand/expand.h"
#include "export/export.h"
#include "s_parser.h"

bool	s_parser(char **line)
{
	t_list	*cut_lst;
	t_list	*unquote_lst;
	char	*temp;

	if (!syntax(*line))
	{
		pnf_fd(2, "bash: error: syntax error\n");
		return (0);
	}
	temp = ft_strtrim(*line, " \n\t");
	free(*line);
	*line = temp;
	if (ft_strlen(*line) < 1)
		return (0);
	if (ft_strchr(*line, '$') != NULL)
		expand(line);
	if (ft_strlen(*line) < 1)
		return (0);
	cut_lst = cut_word(*line);
	unquote_lst = unquote(cut_lst);
	debug_parser(cut_lst, unquote_lst, *line);
	export_to_execute(unquote_lst);
	clear_pars(cut_lst, unquote_lst);
	return (1);
}
