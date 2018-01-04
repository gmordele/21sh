/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_return.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 01:58:10 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/04 00:51:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heredoc_handle_key_return(t_cmd_info *cmd_info)
{
	if (cmd_info->nchar_buf < CMDBUFSIZE - 1)
	{
		cmd_info->complet = 1;
		cmd_info->cmd_buf[cmd_info->nchar_buf] = '\n';
	}
}
