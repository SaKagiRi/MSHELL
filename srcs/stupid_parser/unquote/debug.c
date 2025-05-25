/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:23:33 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 08:29:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../s_parser.h"

#if DEBUG_UNQUOTE==1

static void	temp_fnc(t_list *w)
{
	pnf("\033[1;031m[\033[0m%s\033[1;031m]\033[0m",\
 ((t_unquote *)w->content)->content);
	if (((t_unquote *)w->content)->type == T_READ)
		pnf(" -READ\n");
	else if (((t_unquote *)w->content)->type == T_WRITE)
		pnf(" -WRITE\n");
	else if (((t_unquote *)w->content)->type == T_APPEND)
		pnf(" -APPEND\n");
	else if (((t_unquote *)w->content)->type == T_HEREDOC)
		pnf(" -HEREDOC\n");
	else if (((t_unquote *)w->content)->type == T_PIPE)
		pnf(" -PIPE\n");
	else if (((t_unquote *)w->content)->type == T_CMD)
		pnf(" -CMD\n");
	if (w->next)
		pnf(" ");
}

void	print_debug_unquote(t_list *w, t_list *c, char *line)
{
	pnf("\033[1;031m=======================================\n");
	pnf("=            DEBUG UNQUOTE            =\n");
	pnf("=======================================\033[0m\n\n");
	pnf("\033[1;032minput :\033[0m");
	while (c)
	{
		pnf("\033[1;031m[\033[0m%s\033[1;031m]\033[0m", c->content);
		if (c->next)
			pnf(" ");
		c = c->next;
	}
	pnf("\n");
	pnf("\033[1;033moutput:\033[0m\n ");
	while (w)
	{
		temp_fnc(w);
		w = w->next;
	}
	pnf("\n");
	pnf("\033[1;032m=======================================\n\n\033[0m");
}

#else

void	print_debug_unquote(t_list *w, t_list *c, char *line)
{
	(void)w;
	(void)c;
	(void)line;
}

#endif
