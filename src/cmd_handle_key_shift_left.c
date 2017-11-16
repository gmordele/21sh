/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:37:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:47:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	begin_word(t_cmd_info *cmd_info)
{
	while (cmd_info->buf_pos > 0)
	{
		if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos - 1]))
		{
			cmd_move_cursor_left(cmd_info);
			--(cmd_info->buf_pos);
		}
		else
			break ;
	}
}

static void	init_skip(t_cmd_info *cmd_info)
{
	if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->buf_pos > 0)
	{
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
}

void		cmd_handle_key_shift_left(t_cmd_info *cmd_info)
{
	init_skip(cmd_info);
	while (42)
	{
		if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
			&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
		{
			begin_word(cmd_info);
			break ;
		}
		if (cmd_info->buf_pos > 0)
		{
			cmd_move_cursor_left(cmd_info);
			--(cmd_info->buf_pos);
		}
		else
			break ;
	}
}
