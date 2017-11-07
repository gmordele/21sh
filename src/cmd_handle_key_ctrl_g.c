/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_g.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:12:21 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 16:59:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_ctrl_g(t_cmd_info *cmd_info)
{
	if (cmd_info->in_clipboard)
		cmd_exit_clipboard(cmd_info);
}
