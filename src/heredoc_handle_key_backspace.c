/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_backspace.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:29:50 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/22 02:34:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"

void	heredoc_handle_key_backspace(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->buf_pos > 0)
	{
		heredoc_move_cursor_left();
		--(cmd_info->buf_pos);
		cmd_remove_char(cmd_info);
		if ((cap = tgetstr("dc", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
	}
}
