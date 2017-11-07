/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_enter_exit_clipboard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:55:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 00:47:39 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_enter_clipboard(t_cmd_info *cmd_info)
{
	cmd_info->in_clipboard = 1;
	cmd_info->clip1 = cmd_info->buf_pos;
	cmd_info->clip2 = cmd_info->buf_pos;
}

void cmd_exit_clipboard(t_cmd_info *cmd_info)
{
	(void)cmd_info;
}
