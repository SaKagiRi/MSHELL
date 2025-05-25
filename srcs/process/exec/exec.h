/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:57:58 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 04:11:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdbool.h>
# include "../../../lib/KML/include/kml.h"

/*
execute function
--paramiter
  --cmd
    --[[command] [any argument]]
  --env
    --for find $PATH

--execute failed
  --if it failed must trow erorr "bash: %s: No such file or directory"
    and use [clear function] that clearfunction you can config 
    for [any memory leak] basicly that function use for free [cmd] and [env]
    and last exit at 127 exit code.
*/
void		exec(char **cmd, char **env);

#endif
