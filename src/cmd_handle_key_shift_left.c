/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:37:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/20 02:08:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"
#include "libft.h"

static void	move_back(t_cmd_info *cmd_info)
{
	char	*cap;

	if ((cap = tgetstr("le", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	--(cmd_info->buf_pos);
	--(cmd_info->cur_col);
}

static void	begin_word(t_cmd_info *cmd_info)
{
	(void)cmd_info;
}

static int	init_skip(t_cmd_info *cmd_info)
{
	if (cmd_info->cmd_buf[0] == '\0')
		return (0);
	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
	{
		if (cmd_info->cur_col <= 0)
		{
			cmd_move_prev_line(cmd_info);
			--(cmd_info->buf_pos);
		}
		else
			move_back(cmd_info);
	}
	return (1);
}

void		cmd_handle_key_shift_left(t_cmd_info *cmd_info)
{
	if (!init_skip(cmd_info))
		return ;
	while (42)
	{
		if (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos]))
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
