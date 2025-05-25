/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:31 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 06:04:33 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_parser.h"

void	clear_pars(t_list *c, t_list *u)
{
	ft_lstclear(&c, free);
	ft_lstclear(&u, clear_t_unquote);
}

void	clear_t_unquote(void *u)
{
	free(((t_unquote *)u)->content);
	free(u);
}
