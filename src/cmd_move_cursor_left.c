/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:34:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 03:01:53 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

static void	move_cur_col(int shift)
{
	char	*cap;

	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (shift-- > 0)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

static void	move_prev_line(t_cmd_info *cmd_info)
{
	int		prev_line_len;
	char	*cap;

	if ((prev_line_len = cmd_prev_line_len(cmd_info)) < 0)
		err_exit("Error prev_line_len");
	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	cmd_info->cur_col = prev_line_len;
	--(cmd_info->cur_line);
	move_cur_col(prev_line_len % cmd_info->term_width);
}

void		move_up(t_cmd_info *cmd_info)
{
	char	*cap;

	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	move_cur_col(cmd_info->term_width - 1);
}

static void	handle_clipboard(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos - 1] != '\n')
	{
		if (cmd_info->clip1 >= cmd_info->clip2)
			ft_printf("{BG_WHI}{BLA}%c{RES}",
					  cmd_info->cmd_buf[cmd_info->buf_pos - 1]);
		else
			write(1, cmd_info->cmd_buf + cmd_info->buf_pos - 1, 1);
		if ((cmd_info->cur_col + 1) % cmd_info->term_width != 0)
		{
			if ((cap = tgetstr("le", NULL)) == NULL)
				err_exit("Error tgetstr");
			if (tputs(cap, 1, tputc) < 0)
				err_exit("Error tputs");
		}
	}
	--(cmd_info->clip2);
}

void		cmd_move_cursor_left(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos - 1] == '\n')
		move_prev_line(cmd_info);
	else
	{
		if (cmd_info->cur_col % cmd_info->term_width == 0)
			move_up(cmd_info);
		else
		{
			if ((cap = tgetstr("le", NULL)) == NULL)
				err_exit("Error tgetstr");
			if (tputs(cap, 1, tputc) < 0)
				err_exit("Error tputs");
		}
		--(cmd_info->cur_col);
	}
	if (cmd_info->in_clipboard)
		handle_clipboard(cmd_info);
}
