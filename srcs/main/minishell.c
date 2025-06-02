/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 19:44:21 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"

void	prompt(void)
{
	char	*line;

	while (is_exit(0))
	{
		dup2(*std_in(), 0);
		line = readline("minishell> ");
		if (!line)
			break ;
		add_history(line);
		if (parser(line))
			process();
		clear_t_process();
	}
	close(*std_in());
	rl_clear_history();
}

// NOTE: 
// -sort export, export unset in other case ==>clear
// -error case
// -exit code								==>clear
// -memory leak								==>clear
// NOTE: day 15/4 5:44 Updated
// -finish ft_echo, ft_env, ft_export, ft_pwd, ft_unset and add redirect to it
// -finish all of env, it can read add change and delete
// -finish some leak and big error of memory
// -finish shell level in almost all case 
// (dont have grep case and I dont do it lol)
// -check norm and push update this day
// NOTE: day 25/5 - 29/5 11.25 Update
// - after 4 day I doing parser and now I finish parser to execute struct
// and not leak ok after all I have only one process is a "signal" todo before
// try to submit
// - issue signal, check testcase
int	main(int c, char **v, char **envp)
{
	char	*line;

	init_env(envp);
	prompt();
	clear_env();
	return (0);
}
