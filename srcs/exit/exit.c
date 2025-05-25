/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:14:47 by knakto            #+#    #+#             */
/*   Updated: 2025/05/06 23:11:01 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static int	*ext(void)
{
	static int	ext = 0;

	return (&ext);
}

bool	is_exit(int num)
{
	if (num == 0)
		return (!*ext());
	*ext() = num;
	return (!*ext());
}
