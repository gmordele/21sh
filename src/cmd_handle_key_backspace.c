/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_backspace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:45:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 23:11:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		cmd_handle_key_backspace(t_cmd_info *cmd_info)
{
	if (cmd_info->buf_pos <= 0)
		return ;
	cmd_move_cursor_left(cmd_info);
	--(cmd_info->buf_pos);
	cmd_delete_characters(cmd_info);
	cmd_remove_char(cmd_info);
	cmd_print_characters(cmd_info);
}
