/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:21:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/27 01:40:04 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	chech_eccess(char ***cmd, char *path);
void	clear_execution_failed(char **cmd, char **env);

static char	*get_command_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	return (env[i] + 5);
}

static void	trow_error(char **cmd, char **env)
{
	pnf_fd(2, "bash: %s: No such file or directory\n", cmd[0]);
	clear_execution_failed(cmd, env);
	exit(127);
}

void	exec(char **cmd, char **env)
{
	char	*path;
	bool	status;

	path = get_command_path(env);
	status = chech_eccess(&cmd, path);
	if (!status)
		trow_error(cmd, env);
	execve(cmd[0], cmd, env);
	trow_error(cmd, env);
}
