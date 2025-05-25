/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:21:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 04:24:15 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_process	**get_t_process(void)
{
	static t_process	*process = NULL;

	return (&process);
}
