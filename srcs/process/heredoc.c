/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:24:26 by knakto            #+#    #+#             */
/*   Updated: 2025/05/04 23:26:15 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static char	*create_name_temp_file(int id)
{
	char	*heredoc;
	char	*name_id;
	char	*res;

	heredoc = "/tmp/heredoc_";
	name_id = ft_itoa(id);
	res = ft_strjoin(heredoc, name_id);
	free(name_id);
	return (res);
}

static void	end_heredoc(t_redirect *re, char *name_file, int fd)
{
	if (fd > 0)
		close(fd);
	free(re->value);
	re->value = name_file;
}

void	ft_heredoc(t_redirect *redirect)
{
	static int	id = 0;
	int			fd;
	char		*name_file;
	char		*line;

	name_file = create_name_temp_file(id++);
	fd = open(name_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(0, "> ", 2);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(redirect->value, line, ft_strlen(redirect->value)) \
&& ft_strlen(line) - 1 == ft_strlen(redirect->value))
		{
			end_heredoc(redirect, name_file, fd);
			free(line);
			return ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		write(0, "> ", 2);
		line = get_next_line(0);
	}
	pnf_fd(2, HEREDOC_ERR, redirect->value);
	end_heredoc(redirect, name_file, fd);
}

void	read_all_heredoc(t_process *proc)
{
	t_redirect	*re;

	while (proc)
	{
		re = proc->redirect;
		while (re)
		{
			if (re->type == HERE_DOC)
				ft_heredoc(re);
			re = re->next;
		}
		proc = proc->next;
	}
}
