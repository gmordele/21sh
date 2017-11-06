/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:01:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 02:34:12 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		cmd_move_cursor_end(t_cmd_info *cmd_info)
{
	while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}
