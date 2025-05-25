/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_bind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:10:03 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/05 03:48:18 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static void	new_prompt(int signum)
// {
// 	(void)signum;
// 	g_signal = 1;
// 	write(1, "\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }
//
// void	set_signal_action(int signum, void (*handler)(int))
// {
// 	struct sigaction	sa;
//
// 	sa.sa_handler = handler;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = 0;
// 	if(sigaction(signum, &sa, NULL) == -1)
// 	{
// 		perror("sigaction");
// 		exit(EXIT_FAILURE);
// 	}
// }
//
// void	set_sig_bind_key(void)
// {
// 	set_signal_action(SIGINT, new_prompt);
// 	set_signal_action(SIGQUIT, SIG_IGN);
// }
