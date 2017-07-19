/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_shift_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:19:28 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 14:48:01 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"
#include <stdio.h>
static void	up_same_col(t_cmd_info *cmd_info)
{
	char	*cap;
	int		begin;

	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	begin = (cmd_info->cur_line <= 1) ? cmd_info->prompt_len - 2 : 0;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (begin--)
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

static void	up_end_col(t_cmd_info *cmd_info, int len)
{
	(void)cmd_info;
	(void)len;
}

void		cmd_handle_key_shift_up(t_cmd_info *cmd_info)
{
	int prev_line_len;

	if (cmd_info->cur_line == 0)
		return ;
	prev_line_len = cmd_prev_line_len(cmd_info);
	if (cmd_info->cur_col <= prev_line_len)
		up_same_col(cmd_info);
	else
		up_end_col(cmd_info, prev_line_len);
}
