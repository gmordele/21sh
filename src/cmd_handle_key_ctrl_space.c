/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:10:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/07 00:44:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			cmd_handle_key_ctrl_space(t_cmd_info *cmd_info)
{
	cmd_enter_clipboard(cmd_info);
}
