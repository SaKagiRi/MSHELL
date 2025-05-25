/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:29:49 by knakto            #+#    #+#             */
/*   Updated: 2025/05/07 02:55:38 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

#if DEBUG_EXPAND==1

static void	print_debug_expand(char *line, char *temp)
{
	t_word	*word;
	int		i;

	word = *get_t_word();
	i = 1;
	pnf("\033[1;031m=======================================\n");
	pnf("=            DEBUG EXPAND             =\n");
	pnf("=======================================\n");
	pnf("\033[1;032minput :\033[0m %s\n", line);
	pnf("\033[1;033moutput:\033[0m %s\n", temp);
	pnf("\033[1;034m=======================================\n\n\033[0m");
	while (word)
	{
		pnf("word %d: [%s]\n", i, word->word);
		pnf("expand %d: [%s]\n", i++, word->expand);
		word = word->next;
	}
	pnf("\n\033[1;032m=======================================\n\n\033[0m");
}

#else

static void	print_debug_expand(char	*line, char *temp)
{
	(void)line;
	(void)temp;
}

#endif

void	expand(char **line)
{
	char	*temp;

	expand_word(*line);
	temp = join_line();
	print_debug_expand(*line, temp);
	clear_expand(line, temp);
}
