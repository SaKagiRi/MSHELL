/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:34:19 by knakto            #+#    #+#             */
/*   Updated: 2025/06/03 00:43:45 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include "kml.h"
# include "exit.h"
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>

int		*sig_status(void);
void	sig_prompt();
void	signal_print_newline(int signal);
void	signal_reset_prompt(int signo);
void	sig_handle(int sig);
void	check_sig_status(void);
void	sig_set_null(int sig);
void	signal_prompt(int sig);

#endif
