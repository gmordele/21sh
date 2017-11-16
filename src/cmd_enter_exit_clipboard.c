/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_enter_exit_clipboard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:55:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:48:01 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void		cmd_enter_clipboard(t_cmd_info *cmd_info)
{
	cmd_info->in_clipboard = 1;
	cmd_info->clip1 = cmd_info->buf_pos;
	cmd_info->clip2 = cmd_info->buf_pos;
}

static void	delete_clip1(t_cmd_info *cmd_info)
{
	while (cmd_info->buf_pos != cmd_info->clip1)
	{
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
	cmd_delete_characters(cmd_info);
	cmd_print_characters(cmd_info);
	while (cmd_info->buf_pos != cmd_info->clip2)
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}

static void	delete_clip2(t_cmd_info *cmd_info)
{
	cmd_delete_characters(cmd_info);
	cmd_print_characters(cmd_info);
}

void		cmd_exit_clipboard(t_cmd_info *cmd_info)
{
	if (!cmd_info->in_clipboard)
		return ;
	cmd_info->in_clipboard = 0;
	if (cmd_info->clip2 > cmd_info->clip1)
		delete_clip1(cmd_info);
	else
		delete_clip2(cmd_info);
}
