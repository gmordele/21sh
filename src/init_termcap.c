/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:24:43 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 20:07:09 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "header.h"

void	init_termcap(void)
{
	char	*term_type;

	if ((term_type = env_lst_get_value("TERM")) == NULL)
		term_type = "xterm-256color";
	if (tgetent(NULL, term_type) <= 0)
		err_exit("Error tgetent");
}
