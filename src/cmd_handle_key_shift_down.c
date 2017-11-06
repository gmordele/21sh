/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:19:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 03:45:42 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_last_line(t_cmd_info *cmd_info)
{
	int		pos;

	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\0')
	{
		if (cmd_info->cmd_buf[pos] == '\n')
			return (1);
		++pos;
	}
	return (0);
}

void		cmd_handle_key_shift_down(t_cmd_info *cmd_info)
{
	int		col;

	if (!is_last_line(cmd_info))
		return ;
	col = cmd_info->cur_col;
	col -= (cmd_info->cur_line) == 0 ? cmd_info->prompt_len : 2;
	while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
	
	cmd_move_cursor_right(cmd_info);
	++(cmd_info->buf_pos);

	while (col-- > 0 && cmd_info->cmd_buf[cmd_info->buf_pos] != '\n'
		   && cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);		
	}
}
