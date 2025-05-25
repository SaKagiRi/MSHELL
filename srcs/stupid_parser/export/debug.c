/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:01:39 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 08:28:34 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

#if DEBUG_PROCESS==1

static char	*get_type(t_redirect_type type)
{
	if (type == WRITE_FILE)
		return ("WRITE");
	else if (type == READ_FILE)
		return ("READ");
	else if (type == APPEND_FILE)
		return ("APPEND");
	else if (type == HERE_DOC)
		return ("HEREDOC");
	return (NULL);
}

void	print_debug_process(void)
{
	t_process		*proc;
	t_redirect		*re;
	int				i;
	char			**cmd;

	proc = *get_t_process();
	while (proc)
	{
		cmd = proc->cmd;
		i = 0;
		pnf("cmd: [ ");
		if (cmd[i] == NULL)
			pnf("[NULL] ");
		while (cmd[i])
				pnf("[%s] ", cmd[i++]);
		pnf("]\n");
		re = proc->redirect;
		while (re)
		{
			pnf("	type: %s, redirect: %s\n", get_type(re->type), re->value);
			re = re->next;
		}
		proc = proc->next;
	}
}

#else

void	print_debug_process(void)
{
}

#endif
