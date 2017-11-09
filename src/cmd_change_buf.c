/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_change_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:21:46 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 00:28:08 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void	cmd_change_buf(t_cmd_info *cmd_info, char *cpy_buf, char *save_buf)
{
	cmd_move_cursor_begin(cmd_info);
	cmd_delete_characters(cmd_info);
	ft_memcpy(save_buf, cmd_info->cmd_buf, CMDBUFSIZE);
	ft_memcpy(cmd_info->cmd_buf, cpy_buf, CMDBUFSIZE);
	cmd_info->cur_col = cmd_info->prompt_len;
	cmd_info->cur_line = 0;
	cmd_info->buf_pos = 0;
	cmd_info->nchar_buf = ft_strlen(cmd_info->cmd_buf);
	cmd_info->in_clipboard = 0;
	cmd_info->in_main_buf = 0;
	cmd_print_characters(cmd_info);
	cmd_move_cursor_end(cmd_info);
}
