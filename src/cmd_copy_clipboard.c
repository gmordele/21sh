/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_copy_clipboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:24:13 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 17:40:57 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	copy_clipboard(t_cmd_info *cmd_info, int begin, int end)
{
	int		i;

	i = 0;
	while (i < CMDBUFSIZE - 1 && begin < end)
		(cmd_info->clip_buf)[i++] = (cmd_info->cmd_buf)[begin++];
	(cmd_info->clip_buf)[i] = '\0';
}

void		cmd_copy_clipboard(t_cmd_info *cmd_info)
{
	int		begin;
	int		end;

	if (!cmd_info->in_clipboard || cmd_info->clip1 == cmd_info->clip2)
		return ;
	if (cmd_info->clip1 < cmd_info->clip2)
	{
		begin = cmd_info->clip1;
		end = cmd_info->clip2;
	}
	else
	{
		begin = cmd_info->clip2;
		end = cmd_info->clip1;
	}
	copy_clipboard(cmd_info, begin, end);
}
