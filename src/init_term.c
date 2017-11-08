/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:00:52 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 23:21:58 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "header.h"

static void	save_term(t_term_info *term, struct termios to_save)
{
	term->saved_termios = to_save;
	term->is_saved = 1;
	sta_term_info(term);
}

void		init_termios(void)
{
	struct termios		buf;
	static t_term_info	term;

	if (tcgetattr(0, &buf) < 0)
		err_exit("Error tcgetattr");
	save_term(&term, buf);
	buf.c_lflag &= ~(ECHO | ICANON);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
#ifndef linux
	buf.c_cc[VDSUSP] = _POSIX_VDISABLE;
#endif
	if (tcsetattr(0, TCSANOW, &buf) < 0)
		err_exit("Error tcsetattr");
	tcgetattr(0, &buf);
	if ((buf.c_lflag & (ECHO | ICANON)) || buf.c_cc[VMIN] != 1
		|| buf.c_cc[VTIME] != 0)
		err_exit("Error tcgetattr");
}
