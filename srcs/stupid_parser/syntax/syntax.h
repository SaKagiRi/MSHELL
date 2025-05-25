/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:01:29 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 01:54:48 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "../../../lib/KML/include/kml.h"
# include <stdbool.h>

bool	check_pipe(char *line, int len);
bool	check_quote(char *line);
bool	syntax(char *line);
bool	check_redirect(char *line);

#endif
