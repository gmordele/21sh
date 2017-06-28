/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_return.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:51:01 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/28 21:10:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

static int	is_complet(t_cmd_info *cmd_info)
{
	(void)cmd_info;return 1;
}

void		cmd_handle_key_return(t_cmd_info *cmd_info)
{
	write (1, "\n", 1);
	if (is_complet(cmd_info))
		cmd_info->complet = 1;
	else
	{
		cmd_insert_char(cmd_info, '\n');
		write (1, "> ", 2);
		++(cmd_info->cur_row);
		cmd_info->cur_col = 0;
	}
}
