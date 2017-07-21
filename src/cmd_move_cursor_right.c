/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:33:27 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/20 19:16:17 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

void		cmd_move_cursor_right(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
		return ;
	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		if ((cap = tgetstr("nd", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		++(cmd_info->cur_col);
	}
	else
		cmd_move_next_line(cmd_info);
	++(cmd_info->buf_pos);
}
