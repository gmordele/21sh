/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:22:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 17:05:15 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		cmd_handle_key_delete(t_cmd_info *cmd_info)
{
	if (cmd_info->in_clipboard)
		cmd_exit_clipboard(cmd_info);
	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
		return ;
	cmd_delete_characters(cmd_info);
	cmd_remove_char(cmd_info);
	cmd_print_characters(cmd_info);
}
