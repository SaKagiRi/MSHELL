/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:39:10 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 07:37:31 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static t_env	*get_node(char **env, int i)
{
	char	**temp;
	char	*temp_1;
	t_env	*node;

	node = NULL;
	if (ft_strchr(env[i], '=') == NULL)
		node = new_env(env[i], NULL);
	else
	{
		temp = ft_split(env[i], '=');
		if (ft_strchr(temp[0], '=') != NULL)
		{
			temp_1 = ft_substr(temp[0], 0, ft_strlen(temp[0]) - 1);
			node = new_env(temp_1, "");
			free(temp_1);
		}
		else
			node = new_env(temp[0], temp[1]);
		free_split(temp);
	}
	return (node);
}

void	set_shell_level(void)
{
	t_env	*env;
	int		num;
	char	*val;

	env = *get_t_env();
	while (env)
	{
		if (!ft_strncmp(env->key, "SHLVL", 6))
		{
			if (!env->value)
				env->value = ft_strdup("1");
			else
			{
				num = ft_atoi(env->value);
				if (num < 0)
					val = ft_strdup("0");
				else
					val = ft_itoa(num + 1);
				free(env->value);
				env->value = val;
			}
			return ;
		}
		env = env->next;
	}
}

void	shell_level(void)
{
	if (!search("SHLVL"))
	{
		add_env("SHLVL", "1");
		return ;
	}
	set_shell_level();
}

void	set_minishell_pid(void)
{
	*minishell_pid() = 112548;
}

void	init_env(char **env)
{
	int		i;
	t_env	*node;
	t_env	*current;

	i = 0;
	while (env[i])
	{
		if (i == 0)
		{
			node = get_node(env, i);
			*get_t_env() = node;
			current = node;
		}
		else
		{
			current->next = get_node(env, i);
			current = current->next;
		}
		i++;
	}
	shell_level();
	set_minishell_pid();
	set_env();
}
