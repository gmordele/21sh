/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info_sta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:43:27 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:43:28 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_cmd_info	*cmd_info_sta(t_cmd_info *cmd_info)
{
	static t_cmd_info	*cmd_info_sta = NULL;

	if (cmd_info != NULL)
		cmd_info_sta = cmd_info;
	return (cmd_info_sta);
}
