/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:45:00 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:51:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		cmd_handle_key_shift_right(t_cmd_info *cmd_info)
{
	while (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
	while (ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}
