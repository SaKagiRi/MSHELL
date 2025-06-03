/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:49:12 by knakto            #+#    #+#             */
/*   Updated: 2025/06/03 18:55:41 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "process.h"

static bool	access_relative(char *cmd)
{
	if (!access(cmd, X_OK | F_OK))
		return (true);
	return (false);
}

static void	sub_fnc_access(char **temp, char **all_path, int i, char *cmd)
{
	*temp = ft_strjoin(all_path[i], "/");
	*temp = fjoin(*temp, cmd);
}

static char	*access_absolute(char *cmd, char *path)
{
	char	**all_path;
	char	*temp;
	int		i;
	bool	status;

	if (cmd[0] == '.' || cmd[0] == '/')
		return (ft_strdup(cmd));
	if (ft_strrchr(cmd, '/') != NULL)
		cmd = ft_strrchr(cmd, '/');
	all_path = ft_split(path, ':');
	i = 0;
	status = false;
	while (all_path[i] && !status)
	{
		sub_fnc_access(&temp, all_path, i, cmd);
		if (!access(temp, X_OK | F_OK))
			status = true;
		else
			free(temp);
		i++;
	}
	free_split(all_path);
	if (status)
		return (temp);
	return (NULL);
}

bool	chech_eccess(char ***cmd, char *path)
{
	char	*cmd_path;
	char	*temp;
	bool	relative_status;

	cmd_path = NULL;
	relative_status = access_relative(cmd[0][0]);
	if (!path && !relative_status)
		return (false);
	if (path)
		cmd_path = access_absolute(cmd[0][0], path);
	if (!cmd_path)
	{
		if (relative_status)
			return (true);
		return (false);
	}
	temp = **cmd;
	**cmd = cmd_path;
	free(temp);
	return (true);
}
