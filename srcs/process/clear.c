/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:40:54 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 06:02:31 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	clear_t_redirect(t_redirect *re)
{
	t_redirect	*temp;

	while (re)
	{
		free(re->value);
		temp = re;
		re = re->next;
		free(temp);
	}
}

void	clear_t_process(void)
{
	t_process	*proc;
	t_process	*temp;

	proc = *get_t_process();
	while (proc)
	{
		free_split(proc->cmd);
		clear_t_redirect(proc->redirect);
		temp = proc;
		proc = proc->next;
		free(temp);
	}
	*get_t_process() = NULL;
}
