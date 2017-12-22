/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_key_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 01:29:19 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/22 01:52:30 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heredoc_handle_key_left(t_cmd_info *cmd_info)
{
	if (cmd_info->buf_pos > 0)
	{
		heredoc_move_cursor_left();
		--(cmd_info->buf_pos);
	}
}
