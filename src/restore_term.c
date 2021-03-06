/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:48:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 23:17:00 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include "header.h"

void		restore_term(void)
{
	t_term_info *term;

	term = sta_term_info(NULL);
	if (term != NULL && term->is_saved)
		tcsetattr(0, TCSANOW, &term->saved_termios);
}
