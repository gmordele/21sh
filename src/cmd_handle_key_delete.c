/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:22:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 23:09:54 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"

static void	del_line(t_cmd_info *cmd_info)
{
	char	*cap;

	if ((cap = tgetstr("sc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("dl", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("rc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	cmd_remove_char_del(cmd_info);
	cmd_print_line(cmd_info->cmd_buf + cmd_info->buf_pos);
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

void		cmd_handle_key_delete(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->cmd_buf[cmd_info->buf_pos] == '\0')
		return ;
	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\n')
	{
		if ((cap = tgetstr("dc", NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		cmd_remove_char_del(cmd_info);
	}
	else
		del_line(cmd_info);
}
