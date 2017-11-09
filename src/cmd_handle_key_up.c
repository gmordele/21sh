/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:20:12 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 02:20:55 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void		cmd_handle_key_up(t_cmd_info *cmd_info)
{
	if (cmd_info->hist_lst == NULL)
		return ;
	if (cmd_info->in_main_buf == 1)
	{
		cmd_change_buf(cmd_info, cmd_info->hist_lst->cmd, cmd_info->main_buf);
		cmd_info->in_main_buf = 0;
	}
	else if (cmd_info->hist_lst->prev != NULL)
	{
		cmd_change_buf(cmd_info, cmd_info->hist_lst->prev->cmd,
					cmd_info->hist_lst->cmd);
		cmd_info->hist_lst = cmd_info->hist_lst->prev;
	}
}
