/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_k.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:06:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 04:01:39 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			cmd_handle_key_ctrl_k(t_cmd_info *cmd_info)
{
	int		len;
	int		pos;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
		return ;
	len = 0;
	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\0' && cmd_info->cmd_buf[pos] != '\n')
	{
		++pos;
		++len;
	}
	if (cmd_info->cmd_buf[pos] == '\n')
		++len;
	cmd_delete_characters(cmd_info);
	cmd_remove_n_char(cmd_info, len);
	cmd_print_characters(cmd_info);
}
