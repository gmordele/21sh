/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_begin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:20:25 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 02:32:28 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		cmd_move_cursor_begin(t_cmd_info *cmd_info)
{
	while (cmd_info->buf_pos > 0)
	{
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
}
