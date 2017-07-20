/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:37:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/20 16:41:30 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"
#include "libft.h"

static void	move_back(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cur_col > 0)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		--(cmd_info->cur_col);
	}
	else
		cmd_move_prev_line(cmd_info);
	--(cmd_info->buf_pos);		
}

static void	begin_word(t_cmd_info *cmd_info)
{
	int		col;

	if (cmd_info->cur_col == 0)
		return ;
	col = cmd_info->cur_col;
	while (col > 0)
	{
		--col;
		if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos - 1]))
			move_back(cmd_info);
		else
			break ;
	}

}

static void	init_skip(t_cmd_info *cmd_info)
{
	if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->buf_pos != 0)
		move_back(cmd_info);
}

void		cmd_handle_key_shift_left(t_cmd_info *cmd_info)
{
	init_skip(cmd_info);
	while (42)
	{
		if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
			&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
		{
			begin_word(cmd_info);
			break ;
		}
		if (cmd_info->buf_pos > 0)
			move_back(cmd_info);
		else
			break ;
	}
}
