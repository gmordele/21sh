/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_insert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:06:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 23:03:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_insert_char(t_cmd_info *cmd_info, char c)
{
	int		pos;
	char	tmp1;
	char	tmp2;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
	{
		cmd_info->cmd_buf[cmd_info->buf_pos] = c;
		cmd_info->cmd_buf[cmd_info->buf_pos + 1] = '\0';
		++(cmd_info->nchar_buf);
		return ;
	}
	pos = cmd_info->buf_pos + 1;
	tmp1 = cmd_info->cmd_buf[pos - 1];
	while (cmd_info->cmd_buf[pos] != '\0')
	{
		tmp2 = cmd_info->cmd_buf[pos];
		cmd_info->cmd_buf[pos++] = tmp1;
		tmp1 = tmp2;
	}
	cmd_info->cmd_buf[pos] = tmp1;
	cmd_info->cmd_buf[pos + 1] = '\0';
	cmd_info->cmd_buf[cmd_info->buf_pos] = c;
	++(cmd_info->nchar_buf);
}
