/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_move_cursor_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:34:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 03:10:27 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"
#include "libft.h"

/*
static void	move_cur_col(t_cmd_info *cmd_info)
{
	int 	begin;
	int 	col;
	char	*cap;

	if (cmd_info->cur_line == 0)
		begin = cmd_info->prompt_len + 1;
	else
		begin = 2;
	col = begin + cmd_info->cur_col;
	while (col--)
	{
		if((cap = tgetstr("nd" ,NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
	}
}
*/

static void	move_prev_line(t_cmd_info *cmd_info)
{
	int		prev_line_len;
//	char	*cap;

	prev_line_len = cmd_prev_line_len(cmd_info);
//	ft_printf("\n%d\n", prev_line_len);
	/*
	if((cap = tgetstr("up" ,NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if((cap = tgetstr("cr" ,NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	--(cmd_info->cur_line);
	cmd_info->cur_col = prev_line_len;
	move_cur_col(cmd_info);
	*/
}

void		cmd_move_cursor_left(t_cmd_info *cmd_info)
{
	char	*cap;

	if (cmd_info->buf_pos <= 0)
		return ;
	if (cmd_info->cur_col > 0)
	{
		if((cap = tgetstr("le" ,NULL)) == NULL)
			err_exit("Error tgetstr");
		if (tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
		--(cmd_info->buf_pos);
		--(cmd_info->cur_col);
	}
	else
		move_prev_line(cmd_info);
}
