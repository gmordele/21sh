/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_w.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:11:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:45:23 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	cut(t_cmd_info *cmd_info, int begin, int end)
{
	int		len;

	len = end - begin;
	cmd_delete_characters(cmd_info);
	cmd_remove_n_char(cmd_info, len);
	cmd_print_characters(cmd_info);
	cmd_exit_clipboard(cmd_info);
}

static void	get_begin_end(t_cmd_info *cmd_info, int *begin, int *end)
{
	if (cmd_info->clip1 != cmd_info->clip2)
	{
		if (cmd_info->clip1 < cmd_info->clip2)
		{
			*begin = cmd_info->clip1;
			*end = cmd_info->clip2;
			while (cmd_info->buf_pos != *begin)
			{
				cmd_move_cursor_left(cmd_info);
				--(cmd_info->buf_pos);
			}
		}
		else
		{
			*begin = cmd_info->clip2;
			*end = cmd_info->clip1;
		}
	}
}

void		cmd_handle_key_ctrl_w(t_cmd_info *cmd_info)
{
	int		end;
	int		begin;

	if (!cmd_info->in_clipboard)
		return ;
	if (cmd_info->clip1 != cmd_info->clip2)
	{
		cmd_copy_clipboard(cmd_info);
		get_begin_end(cmd_info, &begin, &end);
		cut(cmd_info, begin, end);
	}
	else
		cmd_exit_clipboard(cmd_info);
}
