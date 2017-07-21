/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:45:00 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/20 20:03:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"
#include "libft.h"

static void	move_next(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		if ((cap = tgetstr("nd", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		++(cmd_info->cur_col);
	}
	else
		cmd_move_next_line(cmd_info);
	++(cmd_info->buf_pos);
}

void		cmd_handle_key_shift_right(t_cmd_info *cmd_info)
{

	while (!ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
		move_next(cmd_info);
	while (ft_isspace(cmd_info->cmd_buf[cmd_info->buf_pos])
		&& cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
		move_next(cmd_info);
	
}
