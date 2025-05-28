/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:09:37 by knakto            #+#    #+#             */
/*   Updated: 2025/05/28 17:47:22 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "process.h"
# include <stdbool.h>
# include "expand.h"
# include "kml.h"

typedef enum e_temp_subfnc
{
	START,
	END
}	t_temp_subfnc;

typedef enum e_token_type
{
	EXPAND = 30,
	OPERATOR,
	STRING,
	WORD,
	IO,
	CMD,
	PIPE,
	REDIRECT,
	VALUE_REDIRECT,
}	t_token_type;

typedef struct s_token
{
	char	*word;
	int		type;
}	t_token;

/*
 * check all parser and return true or false
 *
 * return value
 * - true for parser correct
 * - false for parser have some error and will trow error by it self
*/
bool	parser(char *line);

/*
 * check syntax
 * - invalid pipe
 * - invalid redirect
 * - invalid quote and duble quote  
 *
 * return value
 * - true mean is all syntax pass
 * - false mean syntax not correct and it will trow error
*/
bool	syntax(char *line);

//internal function
void	lexer(t_list **token, char *line);
void	split_space(t_list **token, char *line);
t_token	*new_token(char *word, int type);
void	clear_token(void *token);
void	split_pipe(t_list **token);
bool	check_quote(char c);
void	init_check_quote(void);
bool	have_redirect(t_list *node);
bool	is_redirect(char *str);
int		len_redirect(char *str);
int		type_redirect(char *str);
int		len_till_redirect(char *str);
void	split_redirect(t_list **token);
void	split_one_redirect(t_list **token);
void	append_redirect_type(t_list **token);
void	append_redirect_value_type(t_list **token);
void	append_pipe_type(t_list **token);
void	init_check_double_quote(void);
bool	check_double_quote(char c);
void	expand(t_list *token);

#endif
