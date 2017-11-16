/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:51:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:31:31 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "header.h"

void		init_signals(void)
{
	int		sig;

	(void)sig;
	if (signal(SIGWINCH, sigwinch_handler) == SIG_ERR)
		err_exit("Error signal");
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		err_exit("Error signal");
}
