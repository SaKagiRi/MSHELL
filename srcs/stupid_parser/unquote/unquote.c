/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:30:05 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 10:47:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../s_parser.h"

static void	temp_fnc(char *havequote, int i, bool *d_q, bool *s_q)
{
	if (havequote[i] == '"' && !*s_q)
		*d_q = !*d_q;
	else
		*s_q = !*s_q;
}

static char	*temp_return(char *havequote)
{
	if (!ft_strchr(havequote, '"') && !ft_strchr(havequote, '\''))
		return (ft_strdup(havequote));
	if (ft_strlen(havequote) <= 2)
		return (ft_strdup(""));
	return (NULL);
}

static	char	*temp_init(char *havequote)
{
	char	*res;

	res = temp_return(havequote);
	if (res)
		return (res);
	res = ft_calloc(sizeof(char), ft_strlen(havequote));
	if (!res)
		return (NULL);
	return (res);
}

static char	*coppy_unquote(char *havequote)
{
	bool	s_q;
	bool	d_q;
	int		i;
	int		j;
	char	*res;

	if (!havequote || !*havequote)
		return (NULL);
	if (ft_strlen(havequote) == 2 && (havequote[0] == '"' || havequote[0] == '\''))
		return (ft_strdup(""));
	s_q = false;
	d_q = false;
	res = temp_init(havequote);
	i = 0;
	j = 0;
	while (havequote[i] || res[j])
	{
		if ((havequote[i] == '\'' && !d_q) || (havequote[i] == '"' && !s_q))
			temp_fnc(havequote, i++, &d_q, &s_q);
		else
			res[j++] = havequote[i++];
	}
	while (res[j])
		res[j++] = '\0';
	return (res);
}

t_list	*unquote(t_list *split)
{
	t_list	*lst;
	t_type	type;
	char	*line;

	lst = NULL;
	while (split)
	{
		line = coppy_unquote(split->content);
		type = check_type(split->content);
		if (type == T_REDIRECT && split->next)
			type = check_type_redirect(split->content, split->next->content);
		ft_lstadd_back(&lst, ft_lstnew(new_uql(line, type)));
		split = split->next;
	}
	return (lst);
}
