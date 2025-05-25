/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:58:29 by knakto            #+#    #+#             */
/*   Updated: 2025/05/04 23:26:53 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int	check_builtin(t_process *proc)
{
	if (!ft_strncmp(proc->cmd[0], "cd", 3) \
|| (!ft_strncmp(proc->cmd[0], "export", 7) && proc->cmd[1]) \
|| !ft_strncmp(proc->cmd[0], "unset", 6) \
|| !ft_strncmp(proc->cmd[0], "exit", 5))
	{
		builtin(proc);
		return (1);
	}
	return (0);
}
