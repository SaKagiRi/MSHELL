/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:01:32 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:13:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../s_parser.h"

t_unquote	*new_uql(char *line, t_type type)
{
	t_unquote	*n;

	n = malloc(sizeof(t_unquote));
	if (!n)
		return (NULL);
	n->type = type;
	n->content = line;
	return (n);
}
