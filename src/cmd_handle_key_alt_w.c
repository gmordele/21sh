/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_alt_w.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:13:19 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 17:26:15 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_handle_key_alt_w(t_cmd_info *cmd_info)
{
	if (!cmd_info->in_clipboard)
		return ;
	if (cmd_info->clip1 != cmd_info->clip2)
		cmd_copy_clipboard(cmd_info);
	cmd_exit_clipboard(cmd_info);
}
