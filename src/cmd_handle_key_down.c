/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:20:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 02:30:09 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void		cmd_handle_key_down(t_cmd_info *cmd_info)
{
	if (cmd_info->hist_lst == NULL || cmd_info->in_main_buf == 1)
		return ;
	if (cmd_info->hist_lst->next != NULL)
	{
		cmd_change_buf(cmd_info,
					cmd_info->hist_lst->next->cmd, cmd_info->hist_lst->cmd);
		cmd_info->hist_lst = cmd_info->hist_lst->next;
	}
	else
	{
		cmd_change_buf(cmd_info, cmd_info->main_buf, cmd_info->hist_lst->cmd);
		cmd_info->in_main_buf = 1;
	}
}
