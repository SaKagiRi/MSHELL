/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:03:40 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 07:30:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_env(void)
{
	int		i;

	i = 0;
	while (env()[0][i])
		pnf("%s\n", env()[0][i++]);
}

static void	print(t_env	*env)
{
	if (env->value)
	{
		if (!*env->value)
			pnf("declare -x %s=\n", env->key);
		else
			pnf("declare -x %s=%s\n", env->key, env->value);
	}
	else
		pnf("declare -x %s\n", env->key);
}

void	print_env_list(void)
{
	t_env	*env;

	env = *get_t_env();
	while (env)
	{
		print(env);
		env = env->next;
	}
}
