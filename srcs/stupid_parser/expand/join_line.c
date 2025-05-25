/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:52:34 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 23:55:02 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

char	*join_line(void)
{
	char	*temp;
	t_word	*word;

	if (!*get_t_word())
		return (NULL);
	temp = ft_strdup("");
	word = *get_t_word();
	while (word)
	{
		if (word->expand)
			temp = fjoin(temp, word->expand);
		else
			temp = fjoin(temp, word->word);
		word = word->next;
	}
	return (temp);
}
