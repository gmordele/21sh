/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:00:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 16:56:41 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"

void	enter_insert(void)
{
	char	*cap;

	if ((cap = tgetstr("im", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

int		exit_insert(void)
{
	char	*cap;
	int		ok;

	ok = 1;
	if ((cap = tgetstr("ei", NULL)) == NULL)
		ok = 0;
	if (ok)
		if (tputs(cap, 1, tputc) < 0)
			ok = 0;
	return (ok);
}
