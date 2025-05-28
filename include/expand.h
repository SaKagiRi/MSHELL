/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:31:01 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 21:07:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../../../lib/KML/include/kml.h"
# include "env.h"
# include <limits.h>

typedef struct s_word
{
	char			*word;
	char			*expand;
	struct s_word	*next;
}	t_word;

t_word	**get_t_word(void);
void	clear_t_word(void);
void	expand_line(char **line);
void	expand_word(char *line);
bool	is_in_s_quote(char c);
bool	is_expand(char *line);
char	*join_line(void);
void	clear_expand(char **line, char *temp);
bool	check_quote(char c);
void	init_check_quote(void);
void	init_check_double_quote(void);
bool	check_double_quote(char c);

#endif
