/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:38:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/28 19:19:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

static void	insert_char(t_cmd_info *cmd_info, int c)
{
	int		pos;
	char	tmp1;
	char 	tmp2;

	pos = cmd_info->buf_pos;
	tmp1 = cmd_info->cmd_buf[pos];
	while (cmd_info->cmd_buf[pos + 1] != '\0')
	{
		tmp2 = cmd_info->cmd_buf[pos + 1];
		cmd_info->cmd_buf[pos + 1] = tmp1;
		++pos;
		tmp1 = tmp2;
	}
	cmd_info->cmd_buf[pos + 1] = tmp1;
	cmd_info->cmd_buf[pos + 2] = '\0';
	cmd_info->cmd_buf[cmd_info->buf_pos++] = c;
	++(cmd_info->nchar_buf);
}

void		cmd_handle_key_char(t_cmd_info *cmd_info, int c)
{
	if (cmd_info->nchar_buf >= CMDBUFSIZE - 1)
		return ;
	insert_char(cmd_info, c);
	write(1, &c, 1);
}
