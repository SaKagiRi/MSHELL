/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:33:17 by knakto            #+#    #+#             */
/*   Updated: 2025/05/29 11:24:06 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "process.h"

t_redirect	*ft_new_re(char *eof, int type)
{
	t_redirect	*re;

	re = malloc(sizeof(t_redirect));
	re->value = NULL;
	if (eof)
		re->value = ft_strdup(eof);
	re->next = NULL;
	re->type = type;
	return (re);
}

t_process	*ft_new_proc(char **cmd, t_redirect *re)
{
	t_process	*proc;

	proc = malloc(sizeof(t_process));
	proc->redirect = re;
	proc->cmd = cmd;
	proc->next = NULL;
	return (proc);
}

void	init_porc(void)
{
	*get_t_process() = NULL;
}

void	addback_proc(char **cmd, t_redirect *re)
{
	t_process	*node;

	if (!*get_t_process())
	{
		*get_t_process() = ft_new_proc(cmd, re);
		return ;
	}
	node = *get_t_process();
	while (node->next)
		node = node->next;
	node->next = ft_new_proc(cmd, re);
}

void	addback_re(t_redirect **re, t_token *op, t_token *value)
{
	t_redirect	*node;

	if (!*re)
	{
		*re = ft_new_re(value->word, op->type);
		return ;
	}
	node = *re;
	while (node->next)
		node = node->next;
	node->next = ft_new_re(value->word, op->type);
}
