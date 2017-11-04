/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:38:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/04 03:28:52 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <term.h>
#include "header.h"

void		cmd_handle_key_char(t_cmd_info *cmd_info, int c)
{
	char	*cap;

	if (cmd_info->nchar_buf < CMDBUFSIZE - 1)
	{
		cmd_insert_char(cmd_info, c);
//		cmd_hide_cursor();
		cmd_print_characters(cmd_info);
		cmd_info->buf_pos++;
		cmd_info->nchar_buf++;
		++(cmd_info->cur_col);
		if (cmd_info->cur_col % cmd_info->term_width == 0)
			cmd_move_down();
		else
		{
			if ((cap = tgetstr("nd", NULL)) == NULL)
				err_exit("Error tgetstr");
			if (tputs(cap, 1, tputc) < 0)
				err_exit("Error tputs");
		}
		cmd_show_cursor();
	}
}
