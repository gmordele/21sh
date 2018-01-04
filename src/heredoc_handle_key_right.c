/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:50:49 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/04 17:13:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heredoc_handle_key_right(t_cmd_info *cmd_info)
{
	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		heredoc_move_cursor_right();
		++(cmd_info->buf_pos);
	}
}
