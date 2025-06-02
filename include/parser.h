/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:09:37 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 19:30:26 by knakto           ###   ########.fr       */
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
 * logic
 * - check syntax
 * - lexer ->> split word by word and check append type
 * - expand
 * - unquote
 * - parser to execution struct
 *
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
void	unquote(t_list **token);
void	print_word(t_list *token);
void	addback_proc(char **cmd, t_redirect *re);
void	addback_re(t_redirect **re, t_token *op, t_token *value);
void	init_porc(void);

#endif
