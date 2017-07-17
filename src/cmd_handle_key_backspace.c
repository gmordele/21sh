/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_backspace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:45:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/17 20:14:00 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "header.h"


void		cmd_handle_key_backspace(t_cmd_info *cmd_info)
{
	char 	*cap;

	if (cmd_info->cur_col <= 0)
		return ;
	if ((cap = tgetstr("le", NULL)) == NULL)
		err_exit("Error tgetstr");
	tputs(cap, 1, tputc);
	if ((cap = tgetstr("dc", NULL)) == NULL)
		err_exit("Error tgetstr");
	tputs(cap, 1, tputc);
	cmd_remove_char(cmd_info);
	--(cmd_info->cur_col);
}
