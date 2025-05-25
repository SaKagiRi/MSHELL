/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:32:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/01 20:48:26 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


char *extract_input_word(char *start, int len, t_word_type type)
{
	char *word;
	
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
	{
		word = malloc(len - 1);
		if (!word)
			return (NULL);
		ft_memcpy(word, start + 1, len - 2);
		word[len - 2] = '\0';
	}
	else
	{
		word = malloc(len + 1);
		if (!word)
			return (NULL);
		ft_memcpy(word, start, len);
		word[len] = '\0';
	}
	return (word);
}
t_word_type def_operator(char *str)
{
	if (*str == '<' && *(str + 1) == '<')
		return (HEREDOC);
	else if (*str == '<')
		return (READ);
	else if (*str == '>' && *(str + 1) == '>')
		return (APPEND);
	else if (*str == '>')
		return (WRITE);
	else if (*str == '|')
		return (PIPE);
	else
		return (CMD);
}

int	ft_isoperator(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '<' && *(str + 1) == '<')
		return (1);
	if (*str == '<' || *str == '>')
		return (1);
	if (*str == '>' && *(str + 1) == '>')
		return (1);
	if (*str == '|')
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (c == '\"' || c == '\'')
		return (1);
	else
		return (0);
}
