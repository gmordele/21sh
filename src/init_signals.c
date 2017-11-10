/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:51:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 22:49:01 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "header.h"

void		init_signals(void)
{
	int		sig;

	(void)sig;
	/*
	sig = 1;
	while (sig <= 31)
	{
		if (sig != SIGKILL && sig != SIGSTOP)
			if (signal(sig, SIG_IGN) == SIG_ERR)
				err_exit("Error signal");
		++sig;
	}
	*/
	if (signal(SIGWINCH, sigwinch_handler) == SIG_ERR)
		err_exit("Error signal");
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		err_exit("Error signal");
}
