/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:51:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 15:56:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "header.h"

static void	sigint_handler(int sig)
{
	(void)sig;
	normal_exit();
}

void		init_signals(void)
{
	int		sig;

	sig = 1;
	while (sig <= 31)
	{
		if (sig != 9 && sig != 17)
			if (signal(sig, SIG_IGN) == SIG_ERR)
				err_exit("Error signal");
		++sig;
	}
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		err_exit("Error signal");
}
