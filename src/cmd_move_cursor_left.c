/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:34:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 01:37:19 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

void	cmd_move_cursor_left(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->buf_pos <= 0)
		return ;
	if (cmd_info->cur_col > 0)
	{
		if((cap = tgetstr("le" ,NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		--(cmd_info->buf_pos);
		--(cmd_info->cur_col);
	}
}
