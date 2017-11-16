/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_e.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:22:47 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:46:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_ctrl_e(t_cmd_info *cmd_info)
{
	while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0'
		&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}
