/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:55:23 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 19:09:57 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_pwd(char **arg)
{
	char	thispath[1024];

	if (len_arg(arg) != 1)
	{
		pnf_fd(2, "bash: pwd: too many arguments\n");
		exit(1);
	}
	if (!getcwd(thispath, sizeof(thispath)))
		exit(1);
	pnf("%s\n", thispath);
	exit(0);
}
