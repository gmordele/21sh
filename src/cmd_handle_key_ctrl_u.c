/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:04:14 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/14 18:08:37 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

static void		copy(t_cmd_info *cmd_info, int len)
{
	if (len <= 0 || len >= CMDBUFSIZE)
		return ;
	ft_strncpy(cmd_info->clip_buf, cmd_info->cmd_buf + cmd_info->buf_pos,
		len);
	cmd_info->clip_buf[len] = '\0';
}

void			cmd_handle_key_ctrl_u(t_cmd_info *cmd_info)
{
	int		len;

	if (cmd_info->buf_pos == 0
		|| cmd_info->cmd_buf[cmd_info->buf_pos - 1] == '\n')
		return ;
	len = 0;
	while (cmd_info->buf_pos > 0
		&& cmd_info->cmd_buf[cmd_info->buf_pos - 1] != '\n')
	{
		++len;
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
	cmd_delete_characters(cmd_info);
	copy(cmd_info, len);
	cmd_remove_n_char(cmd_info, len);
	cmd_print_characters(cmd_info);
}
