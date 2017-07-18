/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_backspace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:45:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 23:11:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

static void	del_line(t_cmd_info *cmd_info)
{
	char	*cap;

	if ((cap = tgetstr("dl", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	cmd_move_prev_line(cmd_info);
	cmd_remove_char(cmd_info);
	if ((cap = tgetstr("sc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("rc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

void		cmd_handle_key_backspace(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->buf_pos <= 0)
		return ;
	if (cmd_info->cur_col != 0)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			err_exit("Error tgetstr");
		tputs(cap, 1, tputc);
		if ((cap = tgetstr("dc", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		--(cmd_info->cur_col);
		cmd_remove_char(cmd_info);
	}
	else
		del_line(cmd_info);
}
