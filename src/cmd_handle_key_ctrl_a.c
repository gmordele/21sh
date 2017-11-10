/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:21:14 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 02:21:16 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_ctrl_a(t_cmd_info *cmd_info)
{
	while (cmd_info->buf_pos != 0)
	{
		if (cmd_info->cmd_buf[cmd_info->buf_pos - 1] == '\n')
			break ;
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
}
