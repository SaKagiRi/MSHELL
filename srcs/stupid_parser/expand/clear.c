/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:16:13 by knakto            #+#    #+#             */
/*   Updated: 2025/05/06 00:22:40 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	clear_t_word(void)
{
	t_word	*word;
	t_word	*temp;

	word = *get_t_word();
	while (word)
	{
		temp = word;
		word = word->next;
		free(temp->word);
		if (temp->expand)
			free(temp->expand);
		free(temp);
	}
	*get_t_word() = NULL;
}

void	clear_expand(char **line, char *temp)
{
	free(*line);
	*line = temp;
	clear_t_word();
}
