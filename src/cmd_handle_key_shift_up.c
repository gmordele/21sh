/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:19:28 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 02:15:09 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	prev_line_lenght(t_cmd_info *cmd_info)
{
	int		pos;
	int		len;

	if (cmd_info->cur_line <= 0)
		return (-1);
	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[--pos] != '\n')
	{
		if (pos < 0)
			return (-1);
	}
	--pos;
	len = 1;
	while (pos >= 0 && cmd_info->cmd_buf[pos] != '\n')
	{
		++len;
		--pos;
	}
	return (len);
}

void		cmd_handle_key_shift_up(t_cmd_info *cmd_info)
{
	int prev_line_len;
	int	col;

	if (cmd_info->cur_line == 0)
		return ;
	if ((prev_line_len = prev_line_lenght(cmd_info)) < 0)
		err_exit("Error prev_line_len");
	col = cmd_info->cur_col - 2;
	if (col <= prev_line_len - 1)
	{
		while (prev_line_len--)
		{
			cmd_move_cursor_left(cmd_info);
			--(cmd_info->buf_pos);
		}
	}
	else
		while (col-- > -1)
		{
			cmd_move_cursor_left(cmd_info);
			--(cmd_info->buf_pos);
		}
}
