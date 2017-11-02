/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prev_line_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 01:15:44 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 16:53:07 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmd_prev_line_len(t_cmd_info *cmd_info)
{
	int		pos;
	int		len;


	if (cmd_info->cur_line <= 0)
		return (-1);
	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\n')
	{
		if (pos-- < 0)
			return (-1);
	}
	--pos;
	len = 0;
	while (cmd_info->cmd_buf[pos] != '\n' && pos >= 0)
	{
		++len;
		--pos;
	}
	len += (cmd_info->cur_line == 1) ? cmd_info->prompt_len : 2;
	return (len);
}
