/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:45:02 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:45:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_left(t_cmd_info *cmd_info)
{
	if (cmd_info->buf_pos > 0)
	{
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
}
