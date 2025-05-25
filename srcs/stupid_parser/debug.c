/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:24:51 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:25:45 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_parser.h"

#if DEBUG_CUT_WORD==1

static void	print_debug_cut_word(t_list *c, char *line)
{
	pnf("\033[1;031m=======================================\n");
	pnf("=            DEBUG CUT WORD           =\n");
	pnf("=======================================\n\n\033[0m");
	pnf("\033[1;032minput :\033[0m %s\n", line);
	pnf("\033[1;033moutput:\033[0m");
	while (c)
	{
		pnf("\033[1;031m[\033[0m%s\033[1;031m]\033[0m", c->content);
		if (c->next)
			pnf(" ");
		c = c->next;
	}
	pnf("\n\n");
	pnf("\033[1;032m=======================================\n\n\033[0m");
}

#else

static void	print_debug_cut_word(t_list *c, char *line)
{
	(void)c;
}

#endif

void	debug_parser(t_list *cut_lst, t_list *unquote_lst, char *line)
{
	print_debug_cut_word(cut_lst, line);
	print_debug_unquote(unquote_lst, cut_lst, line);
}
