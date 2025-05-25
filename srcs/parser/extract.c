/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:31:39 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/02 10:39:34 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void clear_word_list(t_word_struct *word_list)
{
	t_word_struct *tmp;
	while (word_list)
	{
		tmp = word_list->next_word;
		free(word_list->word);
		free(word_list);
		word_list = tmp;
	}
}
t_word_type get_word_type(char *start)
{

    if (*start == '<' && *(start + 1) == '<')
        return (HEREDOC); 
    if (*start == '>' && *(start + 1) == '>')
        return (APPEND);
    if (*start == '|' )
        return (PIPE);
    if (*start == '>')
		return (WRITE);
	if (*start == '<')
		return (READ);

    if (ft_isquote(*start))
        return sing_or_double(start);

    return (CMD);
}

int	get_word_len(char *start, t_word_type type)
{
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		return word_len_inquote(start, type);
	else if (type == HEREDOC || type == APPEND)
		return (2);
	else if (type == WRITE 
		|| type == READ
		|| type == PIPE)
		return (1);
	else
		return (word_len(start));
}

void	append_node(t_word_struct **head, t_word_struct *new_node)
{
	t_word_struct	*current;

	if (!new_node)
		return ;

	if (!*head)
	{
		*head = new_node;
		new_node->next_word = NULL;
		return ;
	}
	current = *head;
	while (current->next_word)
		current = current->next_word;
	current->next_word = new_node;
	new_node->next_word = NULL;
}

t_word_struct *create_new_word(char *word, t_word_type type)
{
	t_word_struct	*new_node;

	new_node = malloc(sizeof(t_word_struct));
	if (!new_node)
		return (NULL);
	new_node->word = ft_strdup(word);
	if (!new_node->word)
	{
		free(new_node);
		return (NULL);
	}
	new_node->word_type = type;
	new_node->next_word = NULL;
	return (new_node);
}

static void	process_token(char **start, t_word_struct **head)
{
	t_word_struct	*new_word;
	t_word_type		type;
	int				len;
	char			*word;

	type = get_word_type(*start);
	len = get_word_len(*start, type);
	word = extract_input_word(*start, len, type);
	new_word = create_new_word(word, type);
	append_node(head, new_word);
	free(word);
	*start += len;
}

void	string_extraction(char *line, t_word_struct **head)
{
	char			*start;

	start = line;
	while (*start)
	{
		if (*start && ft_isspace(*start))
			start++;
		else
			process_token(&start, head);
	}
}
