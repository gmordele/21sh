/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_remove_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:03:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:34:39 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_remove_n_char(t_cmd_info *cmd_info, int n)
{
	int		pos1;
	int		pos2;

	pos1 = cmd_info->buf_pos;
	pos2 = pos1 + n;
	while (42)
	{
		cmd_info->cmd_buf[pos1] = cmd_info->cmd_buf[pos2];
		if (cmd_info->cmd_buf[pos1] == '\0')
			break ;
		++pos1;
		++pos2;
	}
	cmd_info->nchar_buf -= n;
}

void	cmd_remove_char(t_cmd_info *cmd_info)
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
