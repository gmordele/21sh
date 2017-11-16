/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_l.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:20:56 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:45:38 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

void		cmd_handle_key_ctrl_l(t_cmd_info *cmd_info)
{
	char	*cap;
	int		pos;

	pos = cmd_info->buf_pos;
	cmd_move_cursor_begin(cmd_info);
	if ((cap = tgetstr("cl", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	print_prompt();
	cmd_print_characters(cmd_info);
	while (cmd_info->buf_pos < pos)
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}
