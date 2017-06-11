/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:11:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 12:26:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

void	move_cursor_right(void)
{
	char	*cap;

	if((cap = tgetstr("nd" ,NULL)) == NULL)
		err_exit_rest("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit_rest("Error tputs");
}

void	move_cursor_left(void)
{
	char	*cap;

	if((cap = tgetstr("le" ,NULL)) == NULL)
		err_exit_rest("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit_rest("Error tputs");
}
