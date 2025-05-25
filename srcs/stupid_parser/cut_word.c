/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:24:48 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 11:02:36 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_parser.h"

static void	first_null(t_list **lst)
{
	t_list	*temp;

	if (((char *)(*lst)->content)[0] == '\0')
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, free);
	}
}

static void	temp_fnc(t_list **lst, char *line, int *i, int *before)
{
	int		n;

	n = 1;
	ft_lstadd_back(lst, ft_lstnew(ft_substr(line, *before, *i - *before)));
	if (line[*i] == '|')
		ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
	if (line[*i] == '<')
		ft_lstadd_back(lst, ft_lstnew(ft_strdup("<")));
	else if (line[*i] == '>')
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(">")));
	*before = *i + n;
}

static int	clear_isspace(void *content, void *ref)
{
	char	*con;

	con = (char *)content;
	(void)ref;
	if (*con == '\0')
		return (1);
	return (0);
}

t_list	*cut_word(char *line)
{
	int		i;
	int		before;
	t_list	*lst;
	bool	d_q;
	bool	s_q;

	i = -1;
	before = 0;
	d_q = false;
	s_q = false;
	lst = NULL;
	while (line[++i])
	{
		if (line[i] == '\'' && !d_q)
			s_q = !s_q;
		if (line[i] == '"' && !s_q)
			d_q = !d_q;
		if ((line[i] == '<' || line[i] == '>' || line[i] == '|' \
|| ft_isspace(line[i])) && !d_q && !s_q)
			temp_fnc(&lst, line, &i, &before);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_substr(line, before, -1)));
	first_null(&lst);
	ft_lstremove_if(&lst, "", clear_isspace, free);
	return (lst);
}
