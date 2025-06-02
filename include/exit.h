/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:15:16 by knakto            #+#    #+#             */
/*   Updated: 2025/06/02 18:55:02 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdbool.h>
# include <stdlib.h>

int		*get_code(void);
int		*std_in(void);
bool	is_exit(int num);

#endif
