/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:28:58 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 02:22:36 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

bool	syntax(char *line)
{
	bool	status;

	status = false;
	if (!check_quote(line) || !check_redirect(line))
		status = true;
	return (!status);
}
