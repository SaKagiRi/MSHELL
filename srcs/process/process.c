/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:37:28 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 10:43:57 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "unistd.h"

static int	len_process(void)
{
	t_process	*proc;
	int			len;

	proc = *get_t_process();
	len = 0;
	while (proc)
	{
		proc = proc->next;
		len++;
	}
	return (len);
}

static int	is_builtin(t_process *proc)
{
	if (!ft_strncmp(proc->cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "export", 7) && !proc->cmd[1])
		return (1);
	else
		return (0);
}

static void	run_process(t_process *proc, int sw)
{
	int	pipe_fd[2];

	pipe(pipe_fd);
	proc->pid = fork();
	if (proc->pid < 0)
	{
		pnf_fd(2, "bash: error: broken fork\n");
		clear_t_process();
		exit(1);
	}
	if (proc->pid == 0)
	{
		close(pipe_fd[0]);
		if (sw)
			dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		redirect(proc);
		if (is_builtin(proc))
			builtin(proc);
		exec(proc->cmd, *env());
	}
	close(pipe_fd[1]);
	if (sw)
		dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
}

static void	ft_wait_proc(int all_proc, pid_t last_pid)
{
	int		i;
	int		temp_code;
	int		temp_pid;

	i = 0;
	temp_code = 0;
	temp_pid = 0;
	while (i < all_proc)
	{
		temp_pid = wait(&temp_code);
		if (temp_pid == last_pid)
			*get_code() = temp_code / 256;
		i++;
	}
}

void	process(void)
{
	t_process	*proc;
	int			all_proc;
	int			exit_status;
	pid_t		last_pid;

	proc = *get_t_process();
	read_all_heredoc(proc);
	if (check_builtin(proc))
		return ;
	all_proc = len_process();
	last_pid = 0;
	while (proc)
	{
		if (proc->next)
			run_process(proc, 1);
		else
		{
			run_process(proc, 0);
			last_pid = proc->pid;
		}
		proc = proc->next;
	}
	ft_wait_proc(all_proc, last_pid);
	clear_t_process();
}
