/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:34:42 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:27:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	redirect_add_back(t_redirect **re, char *value, t_redirect_type type)
{
	t_redirect	*node;

	node = *re;
	if (!node)
	{
		*re = new_redirect(value, type);
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new_redirect(value, type);
}

void	proc_add_back(t_process **proc, char **cmd, t_redirect *re)
{
	t_process	*node;

	node = *proc;
	if (!node)
	{
		*proc = new_proc(cmd, re);
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new_proc(cmd, re);
}

t_redirect	*new_redirect(char *value, t_redirect_type type)
{
	t_redirect	*re;

	re = malloc(sizeof(t_redirect));
	if (!re)
		return (NULL);
	re->type = type;
	re->value = value;
	re->next = NULL;
	return (re);
}

t_process	*new_proc(char **cmd, t_redirect *re)
{
	t_process	*proc;

	proc = malloc(sizeof(t_process));
	if (!proc)
		return (NULL);
	proc->cmd = cmd;
	proc->pid = 0;
	proc->redirect = re;
	proc->next = NULL;
	return (proc);
}
