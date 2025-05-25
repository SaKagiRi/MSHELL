/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:31:01 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 23:58:06 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../../../lib/KML/include/kml.h"
# include "../../environment_variables/env.h"
# include <limits.h>

typedef struct s_word
{
	char			*word;
	char			*expand;
	struct s_word	*next;
}	t_word;

t_word	**get_t_word(void);
void	clear_t_word(void);
void	expand(char **line);
void	expand_word(char *line);
bool	is_in_s_quote(char c);
bool	is_expand(char *line);
char	*join_line(void);
void	clear_expand(char **line, char *temp);

#endif
