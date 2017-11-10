/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:04:14 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 04:06:06 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_ctrl_u(t_cmd_info *cmd_info)
{
	int		pos;
	int		len;

	if (cmd_info->buf_pos == 0 || cmd_info->cmd_buf[cmd_info->buf_pos] == '\n')
	{}
}
