/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:39:54 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/14 18:24:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

void		init_cmd(t_cmd_info *cmd_info, int prompt_len, char *cmd_buf,
					int options)
{
	static int start = 1;

	cmd_info->options = options;
	ft_memset(cmd_buf, 0, CMDBUFSIZE);
	cmd_info->cmd_buf = cmd_buf;
	cmd_info->prompt_len = prompt_len;
	cmd_info->cur_line = 0;
	cmd_info->cur_col = prompt_len;
	cmd_info->complet = 0;
	cmd_info->buf_pos = 0;
	cmd_info->nchar_buf = 0;
	cmd_info->term_width = cmd_get_term_width();
	cmd_info->in_clipboard = 0;
	if (start == 1)
	{
		start = 0;
		ft_memset(cmd_info->clip_buf, 0, CMDBUFSIZE);
	}
	cmd_info->hist_lst = *hist_lst_sta(NULL);
	cmd_info->in_main_buf = 1;
	ft_memset(cmd_info->main_buf, 0, CMDBUFSIZE);
}

static void	cmd_handle_key3(t_cmd_info *cmd_info, int key)
{
	if (key == KEY_CTRL_L)
		cmd_handle_key_ctrl_l(cmd_info);
	else if (key == KEY_CTRL_K)
		cmd_handle_key_ctrl_k(cmd_info);
	else if (key == KEY_CTRL_U)
		cmd_handle_key_ctrl_u(cmd_info);
	else if (key == KEY_CTRL_D)
		cmd_handle_key_ctrl_d(cmd_info);
}

static void	cmd_handle_key2(t_cmd_info *cmd_info, int key)
{
	if (key == KEY_END)
		cmd_move_cursor_end(cmd_info);
	else if (key == KEY_CTRL_SPACE)
		cmd_handle_key_ctrl_space(cmd_info);
	else if (key == KEY_CTRL_X)
		cmd_handle_key_ctrl_x(cmd_info);
	else if (key == KEY_CTRL_A)
		cmd_handle_key_ctrl_a(cmd_info);
	else if (key == KEY_CTRL_E)
		cmd_handle_key_ctrl_e(cmd_info);
	else if (key == KEY_CTRL_G)
		cmd_handle_key_ctrl_g(cmd_info);
	else if (key == KEY_ALT_W)
		cmd_handle_key_alt_w(cmd_info);
	else if (key == KEY_CTRL_Y)
		cmd_handle_key_ctrl_y(cmd_info);
	else if (key == KEY_CTRL_W)
		cmd_handle_key_ctrl_w(cmd_info);
	else if (key == KEY_UP || key == KEY_CTRL_P)
		cmd_handle_key_up(cmd_info);
	else if (key == KEY_DOWN || key == KEY_CTRL_N)
		cmd_handle_key_down(cmd_info);
	else
		cmd_handle_key3(cmd_info, key);
}

static void	cmd_handle_key(t_cmd_info *cmd_info, int key)
{
	if (ft_isprint(key))
		cmd_handle_key_char(cmd_info, key);
	else if (key == KEY_RETURN)
		cmd_handle_key_return(cmd_info);
	else if (key == KEY_BACKSPACE)
		cmd_handle_key_backspace(cmd_info);
	else if (key == KEY_LEFT || key == KEY_CTRL_B)
		cmd_handle_key_left(cmd_info);
	else if (key == KEY_RIGHT || key == KEY_CTRL_F)
		cmd_handle_key_right(cmd_info);
	else if (key == KEY_DELETE)
		cmd_handle_key_delete(cmd_info);
	else if (key == KEY_SHIFT_UP)
		cmd_handle_key_shift_up(cmd_info);
	else if (key == KEY_SHIFT_DOWN)
		cmd_handle_key_shift_down(cmd_info);
	else if (key == KEY_SHIFT_LEFT)
		cmd_handle_key_shift_left(cmd_info);
	else if (key == KEY_SHIFT_RIGHT)
		cmd_handle_key_shift_right(cmd_info);
	else if (key == KEY_HOME)
		cmd_move_cursor_begin(cmd_info);
	else
		cmd_handle_key2(cmd_info, key);
}

void		cmd_get(char *cmd_buf, int prompt_len, int options)
{
	char				read_buf[READBUFSIZE];
	int					key;
	int					n;
	static t_cmd_info	cmd_info;

	cmd_info_init(&cmd_info, prompt_len, cmd_buf, options);
	cmd_info_sta(&cmd_info);
	while (!cmd_info.complet)
	{
		if ((n = read(0, read_buf, READBUFSIZE)) <= 0)
			err_exit("Error read");
		key = cmd_pressed_key(n, read_buf);
		cmd_handle_key(&cmd_info, key);
	}
}
