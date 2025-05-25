/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_to_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:06:39 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 11:04:47 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"
#include "../s_parser.h"

static int	temp_fnc(t_list *lst, t_redirect **re)
{
	if (((t_unquote *)lst->content)->type == T_READ)
	{
		redirect_add_back(re, \
ft_strdup(((t_unquote *)lst->next->content)->content), READ_FILE);
		return (2);
	}
	else if (((t_unquote *)lst->content)->type == T_WRITE)
	{
		redirect_add_back(re, \
ft_strdup(((t_unquote *)lst->next->content)->content), WRITE_FILE);
		return (2);
	}
	else if (((t_unquote *)lst->content)->type == T_APPEND)
	{
		redirect_add_back(re, \
ft_strdup(((t_unquote *)lst->next->next->content)->content), APPEND_FILE);
		return (3);
	}
	else if (((t_unquote *)lst->content)->type == T_HEREDOC)
	{
		redirect_add_back(re, \
ft_strdup(((t_unquote *)lst->next->next->content)->content), HERE_DOC);
		return (3);
	}
	return (1);
}

static t_redirect	*redirect_till_pipe(t_list *lst)
{
	t_redirect	*re;
	int			i;

	re = NULL;
	i = 0;
	while (lst && ((t_unquote *)lst->content)->type != T_PIPE)
	{
		i = temp_fnc(lst, &re);
		if (i == 1)
			lst = lst->next;
		else if (i == 2)
			lst = lst->next->next;
		else if (i == 3)
			lst = lst->next->next->next;
	}
	return (re);
}

static int		len_cmd_till_pipe(t_list *lst)
{
	int			i;
	t_unquote	*u;

	i = 0;
	while (lst)
	{
		u = lst->content;
		if (u->type == T_PIPE)
			return (i);
		if (u->type == T_APPEND || u->type == T_HEREDOC)
			lst = lst->next->next;
		else 
		{
			if (!(u->type == T_READ || u->type == T_WRITE))
				i++;
			lst = lst->next;
		}
	}
	return (i);
}

static char	**cmd_till_pipe(t_list *lst)
{
	int			len;
	int			i;
	t_unquote	*u;
	char		**arg;

	len = len_cmd_till_pipe(lst);
	arg = malloc(sizeof(char *) * (len + 1));
	if (!arg)
		return (NULL);
	i = 0;
	while (i < len && lst && ((t_unquote *)lst->content)->type != T_PIPE)
	{
		u = lst->content;
		if (u->type == T_APPEND || u->type == T_HEREDOC)
			lst = lst->next->next;
		else if (u->type == T_READ || u->type == T_WRITE)
			lst = lst->next;
		else if (((t_unquote *)lst->content)->type == T_CMD)
			arg[i++] = ft_strdup(((t_unquote *)lst->content)->content);
		lst = lst->next;
	}
	arg[i] = NULL;
	return (arg);
}

void	export_to_execute(t_list *u)
{
	int			block;
	char		**cmd;
	t_process	*proc;
	t_redirect	*re;

	block = 1;
	proc = NULL;
	while (u)
	{
		if (((t_unquote *)u->content)->type == T_PIPE)
		{
			block = 1;
			u = u->next;
		}
		if (block == 1)
		{
			cmd = cmd_till_pipe(u);
			re = redirect_till_pipe(u);
			proc_add_back(get_t_process(), cmd, re);
		}
		block = 0;
		u = u->next;
	}
	print_debug_process();
}
