/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:01:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 19:05:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "header.h"

static void	move_cursor_down(void)
{
	char	*cap;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

void		cmd_move_cursor_end(t_cmd_info *cmd_info)
{
	char	*cap;

	while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\n')
		{
			move_cursor_down();
			cmd_info->cur_col = 0;
			++(cmd_info->cur_line);
		}
		else
		{
			if ((cap = tgetstr("nd", NULL)) == NULL)
				err_exit("Error tgetstr");
			if (tputs(cap, 1, tputc) < 0)
				err_exit("Error tputs");
			++(cmd_info->cur_col);
		}
		++(cmd_info->buf_pos);
	}
}
