/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:33:27 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 02:47:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"
#include "unistd.h"
#include "libft.h"

static void	move_next_line(void)
{
	char *cap;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

static void	handle_clipboard(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		if (cmd_info->clip1 <= cmd_info->clip2)
			ft_printf("{BG_WHI}{BLA}%c{RES}",
					  cmd_info->cmd_buf[cmd_info->buf_pos]);
		else
			write(1, cmd_info->cmd_buf + cmd_info->buf_pos, 1);
		if ((cap = tgetstr("le", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
	}
	++(cmd_info->clip2);
}

void		cmd_move_cursor_right(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->in_clipboard)
		handle_clipboard(cmd_info);
	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\n')
	{
		move_next_line();
		cmd_info->cur_col = 2;
		++(cmd_info->cur_line);
	}
	else if ((cmd_info->cur_col + 1) % cmd_info->term_width == 0)
	{
		cmd_move_down();
		++(cmd_info->cur_col);
	}
	else
	{
		if ((cap = tgetstr("nd", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		++(cmd_info->cur_col);
	}
}
