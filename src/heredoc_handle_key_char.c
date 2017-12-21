/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:19:02 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/22 00:25:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void	heredoc_handle_key_char(t_cmd_info *cmd_info, int c)
{
	if (cmd_info->nchar_buf < CMDBUFSIZE - 1)
	{
		cmd_delete_characters(cmd_info);
		cmd_insert_char(cmd_info, c);
		write(1, &c, 1);
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
