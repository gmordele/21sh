/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_y.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:53:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 18:57:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void	cmd_handle_key_ctrl_y(t_cmd_info *cmd_info)
{
	int		clip_len;

	if (cmd_info->in_clipboard)
		cmd_exit_clipboard(cmd_info);
	clip_len = ft_strlen(cmd_info->clip_buf);
	if (clip_len == 0)
		return ;
	if (clip_len + cmd_info->nchar_buf < CMDBUFSIZE)
	{
		cmd_delete_characters(cmd_info);
		cmd_insert_n_char(cmd_info, cmd_info->clip_buf, clip_len);
		cmd_print_characters(cmd_info);
		while (clip_len-- > 0)
		{
			cmd_move_cursor_right(cmd_info);
			++(cmd_info->buf_pos);
		}
	}
}
