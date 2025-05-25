/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:34:32 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:24:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PARSER_H
# define S_PARSER_H

# include <stdbool.h>
# include "syntax/syntax.h"
# include "expand/expand.h"
# include "../process/process.h"
# include "export/export.h"

typedef enum e_type
{
	T_PIPE,
	T_REDIRECT,
	T_READ,
	T_WRITE,
	T_APPEND,
	T_HEREDOC,
	T_CMD,
}	t_type;

typedef struct s_unquote
{
	t_type	type;
	char	*content;
}	t_unquote;

bool		s_parser(char **line);
t_list		*cut_word(char *line);
t_list		*unquote(t_list *split);
void		debug_parser(t_list *cut_lst, t_list *unquote_lst, char *line);
void		clear_pars(t_list *c, t_list *u);
int			is_redirect(char *s);
t_type		check_type(char *line);
t_type		check_type_redirect(char *s1, char *s2);
t_unquote	*new_uql(char *line, t_type type);
void		clear_t_unquote(void *u);
void		print_debug_unquote(t_list *w, t_list *c, char *line);

#endif
