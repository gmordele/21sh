/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:00:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 15:04:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"

void	enter_insert(void)
{
	char	*cap;

	if((cap = tgetstr("im" ,NULL)) == NULL)
		err_exit_rest("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit_rest("Error tputs");
}

void	exit_insert(void)
{
	char	*cap;

	if((cap = tgetstr("ei" ,NULL)) == NULL)
		err_exit_rest("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit_rest("Error tputs");
}
