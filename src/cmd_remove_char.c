/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_remove_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:03:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 22:42:41 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_remove_char(t_cmd_info *cmd_info)
{
	int		pos;

	pos = cmd_info->buf_pos - 1;
	while (42)
	{
		cmd_info->cmd_buf[pos] = cmd_info->cmd_buf[pos + 1];
		if (cmd_info->cmd_buf[pos] == '\0')
			break ;
		++pos;
	}
	--(cmd_info->buf_pos);
	--(cmd_info->nchar_buf);
}

void	cmd_remove_char_del(t_cmd_info *cmd_info)
{
	int		pos;

	pos = cmd_info->buf_pos;
	while (42)
	{
		cmd_info->cmd_buf[pos] = cmd_info->cmd_buf[pos + 1];
		if (cmd_info->cmd_buf[pos] == '\0')
			break ;
		++pos;
	}
	--(cmd_info->nchar_buf);
}
