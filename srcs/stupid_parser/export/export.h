/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:41:10 by knakto            #+#    #+#             */
/*   Updated: 2025/05/12 07:27:27 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../../process/process.h"

t_redirect	*new_redirect(char *value, t_redirect_type type);
t_process	*new_proc(char **cmd, t_redirect *re);
void		redirect_add_back(t_redirect **re, char *value,\
 t_redirect_type type);
void		proc_add_back(t_process **proc, char **cmd, t_redirect *re);
void		export_to_execute(t_list *u);
void		print_debug_process(void);

#endif
