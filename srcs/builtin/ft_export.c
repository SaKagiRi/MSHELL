/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 05:04:28 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 19:09:21 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	set_export(char **arg)
{
	int		i;
	char	**temp;
	char	*sub;

	i = 1;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '=') != NULL)
		{
			temp = ft_split(arg[i], '=');
			if (ft_strchr(temp[0], '=') != NULL)
			{
				sub = ft_substr(temp[0], 0, ft_strlen(arg[i]) - 1);
				add_env(sub, "");
				free(sub);
			}
			else
				add_env(temp[0], temp[1]);
			free_split(temp);
		}
		else
			add_env(arg[i], NULL);
		i++;
	}
}

void	ft_export(char **arg)
{
	if (len_arg(arg) == 1)
	{
		print_env_list();
		exit(0);
	}
	set_export(arg);
}
