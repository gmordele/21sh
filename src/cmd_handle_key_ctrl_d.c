/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:19:38 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/14 18:24:52 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void		cmd_handle_key_ctrl_d(t_cmd_info *cmd_info)
{
	if (cmd_info->nchar_buf == 0)
	{
		write(1, "exit\n", 6);
		normal_exit();
	}
	else
		cmd_handle_key_delete(cmd_info);
}
