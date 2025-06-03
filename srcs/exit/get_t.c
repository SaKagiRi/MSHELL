/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:41:35 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 20:19:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <unistd.h>

int	*get_code(void)
{
	static int	status = 0;

	return (&status);
}

int	*std_in(void)
{
	static int	fd = -10;

	if (fd == -10)
		fd = dup(0);
	return (&fd);
}
