/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_begin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:20:25 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/20 21:20:38 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"

static void	up_same_col(t_cmd_info *cmd_info)
{
	char	*cap;
	int		begin;

	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	begin = (cmd_info->cur_line <= 1) ? cmd_info->prompt_len - 2 : 0;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (begin--)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

static void	up_end_col(t_cmd_info *cmd_info, int prev_line_len)
{
	char	*cap;
	int		gap;

	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	gap = cmd_info->cur_col - prev_line_len
		- ((cmd_info->cur_line <= 1) ? cmd_info->prompt_len - 2: 0);
	if (gap > 0)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			err_exit("Error tgetstr");
		while (gap--)
			if (tputs(cap, 1, tputc) < 0)
				err_exit("Error tputs");
		return ;
	}
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (gap++)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

static void	move_begin_line(t_cmd_info *cmd_info)
{
	char	*cap;

	while (cmd_info->buf_pos > 0)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		--(cmd_info->buf_pos);
		--(cmd_info->cur_col);
	}
}

static void	move_prev_line_buf(t_cmd_info *cmd_info)
{
	int prev_line_len;

	if (cmd_info->cur_line == 0)
	{
		move_begin_line(cmd_info);
		return ;
	}
	if ((prev_line_len = cmd_prev_line_len(cmd_info)) < 0)
		err_exit("Error prev_line_len");
	if (cmd_info->cur_col <= prev_line_len)
	{
		up_same_col(cmd_info);
		cmd_info->buf_pos -= prev_line_len + 1;
	}
	else
	{
		up_end_col(cmd_info, prev_line_len);
		cmd_info->buf_pos -= cmd_info->cur_col + 1;
		cmd_info->cur_col = prev_line_len;
	}
	--(cmd_info->cur_line);
}

void		cmd_move_cursor_begin(t_cmd_info *cmd_info)
{
	while (cmd_info->cur_line > 0)
		move_prev_line_buf(cmd_info);
	move_begin_line(cmd_info);
}
