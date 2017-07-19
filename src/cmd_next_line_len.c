/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_next_line_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:30:25 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 18:59:55 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmd_next_line_len(t_cmd_info *cmd_info)
{
	int		pos;
	int		len;

	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\n')
	{
		if (cmd_info->cmd_buf[pos] == '\0')
			return (-1);
		++pos;
	}
	++pos;
	len = 0;
	while (cmd_info->cmd_buf[pos] != '\n' && cmd_info->cmd_buf[pos] != '\0')
	{
		++len;
		++pos;
	}
	return (len);
}
