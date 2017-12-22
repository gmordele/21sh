/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_ctrl_d.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:56:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/22 02:57:55 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heredoc_handle_key_ctrl_d(t_cmd_info *cmd_info)
{
	if (cmd_info->cmd_buf[0] == '\0')
		cmd_info->complet = 1;
	else
		heredoc_handle_key_delete(cmd_info);
}
