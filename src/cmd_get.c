/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:39:54 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 23:37:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

static void	init_cmd(t_cmd_info *cmd_info, int prompt_len, char *cmd_buf)
{
	cmd_buf[0] = '\0';
	cmd_info->prompt_len = prompt_len;
	cmd_info->cur_line = 0;
	cmd_info->cur_col = 0;
	cmd_info->complet = 0;
	cmd_info->cmd_buf = cmd_buf;
	cmd_info->buf_pos = 0;
	cmd_info->nchar_buf = 0;
}

void		cmd_handle_key(t_cmd_info *cmd_info, int key)
{
	if (ft_isprint(key))
		cmd_handle_key_char(cmd_info, key);
	else if (key == KEY_RETURN)
		cmd_handle_key_return(cmd_info);
	else if (key == KEY_BACKSPACE)
		cmd_handle_key_backspace(cmd_info);
	else if (key == KEY_LEFT)
		cmd_move_cursor_left(cmd_info);
	else if (key == KEY_RIGHT)
		cmd_move_cursor_right(cmd_info);
	else if (key == KEY_CTRL_D || key == KEY_DELETE)
		cmd_handle_key_delete(cmd_info);
	else if (key == KEY_SHIFT_UP)
		cmd_handle_key_shift_up(cmd_info);
	else if (key == KEY_SHIFT_DOWN)
		cmd_handle_key_shift_down(cmd_info);
	else if (key == KEY_SHIFT_LEFT)
		cmd_handle_key_shift_left(cmd_info);
}

void		cmd_get(char *cmd_buf, int prompt_len)
{
	char		read_buf[READBUFSIZE];
	int			key;
	int			n;
	t_cmd_info	cmd_info;

	init_cmd(&cmd_info, prompt_len, cmd_buf);
	while (!cmd_info.complet)
	{
		if ((n = read(0, read_buf, READBUFSIZE)) <= 0)
			err_exit("Error read");
		key = pressed_key(n, read_buf);
		cmd_handle_key(&cmd_info, key);
	}
}
