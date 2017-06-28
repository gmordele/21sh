/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:11:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/28 19:39:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

void	cmd_move_cursor_right(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
		return ;
	if((cap = tgetstr("nd" ,NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	++(cmd_info->buf_pos);
	++(cmd_info->cur_col);
}

void	cmd_move_cursor_left(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cur_col <= 0)
		return ;
	if((cap = tgetstr("le" ,NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	--(cmd_info->buf_pos);
	--(cmd_info->cur_col);
}
