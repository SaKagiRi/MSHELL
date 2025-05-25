/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:38:45 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 19:09:36 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(char **arg)
{
	if (len_arg(arg) != 1)
	{
		pnf_fd(2, "bash: env: too many arguments\n");
		exit(1);
	}
	print_env();
	exit(0);
}
