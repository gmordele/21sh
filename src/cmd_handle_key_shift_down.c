/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:19:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 20:05:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"

static void	new_buf_pos(t_cmd_info *cmd_info, int add_pos)
{
	while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
		++(cmd_info->buf_pos);
	cmd_info->buf_pos += add_pos;
}

static void	down_same_col(t_cmd_info *cmd_info)
{
	char	*cap;
	int		col;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	col = cmd_info->cur_col + 2;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (col-- > 0)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

static void	down_col(int next_col)
{
	char	*cap;
	int		col;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	col = next_col + 2;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (col-- > 0)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

void		cmd_handle_key_shift_down(t_cmd_info *cmd_info)
{
	int		next_line_len;

	next_line_len = cmd_next_line_len(cmd_info);
	if (next_line_len < 0)
	{
		cmd_move_cursor_end(cmd_info);
		return ;
	}
	if (cmd_info->cur_col <= next_line_len)
	{
		down_same_col(cmd_info);
		new_buf_pos(cmd_info, cmd_info->cur_col + 1);
	}
	else
	{
		down_col(next_line_len);
		new_buf_pos(cmd_info, next_line_len + 1);
		cmd_info->cur_col = next_line_len;
	}
	++(cmd_info->cur_line);
}
