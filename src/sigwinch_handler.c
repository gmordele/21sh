/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigwinch_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:48:43 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 01:13:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void		sigwinch_handler(int sig)
{
	t_cmd_info		*cmd_info;

	(void)sig;
	if ((cmd_info = cmd_info_sta(NULL)) == NULL)
		err_exit("Error cmd_info_sta");
	cmd_info->term_width = cmd_get_term_width();
	cmd_handle_key_ctrl_l(cmd_info);
}
