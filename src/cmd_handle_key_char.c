/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:38:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 17:06:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <term.h>
#include "header.h"

void		cmd_handle_key_char(t_cmd_info *cmd_info, int c)
{
	char	*cap;

	if (cmd_info->in_clipboard)
		cmd_exit_clipboard(cmd_info);
	if (cmd_info->nchar_buf < CMDBUFSIZE - 1)
	{
		cmd_delete_characters(cmd_info);
		cmd_insert_char(cmd_info, c);
		cmd_print_characters(cmd_info);
		cmd_info->buf_pos++;
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
	}
}
