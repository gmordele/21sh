/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:38:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/28 21:07:47 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void		cmd_handle_key_char(t_cmd_info *cmd_info, int c)
{
	if (cmd_info->nchar_buf >= CMDBUFSIZE - 1)
		return ;
	cmd_insert_char(cmd_info, c);
	++(cmd_info->cur_col);
	write(1, &c, 1);
}
