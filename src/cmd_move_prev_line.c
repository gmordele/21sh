/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_prev_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:41:52 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 17:42:19 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

static void	move_cur_col(t_cmd_info *cmd_info)
{
	int		begin;
	int		col;
	char	*cap;

	if (cmd_info->cur_line == 0)
		begin = cmd_info->prompt_len;
	else
		begin = 2;
	col = begin + cmd_info->cur_col;
	while (col--)
	{
		if ((cap = tgetstr("nd", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
	}
}

void		cmd_move_prev_line(t_cmd_info *cmd_info)
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
	move_cur_col(cmd_info);
}
