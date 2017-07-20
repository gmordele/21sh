/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:33:27 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 17:10:09 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

static void	move_next_line(t_cmd_info *cmd_info)
{
	char *cap;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	++(cmd_info->cur_line);
	cmd_info->cur_col = 0;
}

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
		move_next_line(cmd_info);
	++(cmd_info->buf_pos);
}