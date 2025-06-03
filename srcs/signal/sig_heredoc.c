/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:00:48 by knakto            #+#    #+#             */
/*   Updated: 2025/06/03 01:00:56 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	sig_set_null(int sig)
{
	int devnull = open("/dev/null", O_RDONLY);
	dup2(devnull, STDIN_FILENO);
	close(devnull);
	*sig_status() = 2;
}

void	signal_prompt(int sig)
{
	(void)sig;

	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
