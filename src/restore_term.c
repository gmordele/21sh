/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:48:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 15:04:45 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include "header.h"

void		restore_term(void)
{
	t_term_info *term;

	exit_insert();
	term = sta_term_info(NULL);
	if (term->is_saved)
		if (tcsetattr(0, TCSANOW, &term->saved_termios) < 0)
			err_exit( "Error tcsetattr");
}
