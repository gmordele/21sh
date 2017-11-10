/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:46:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 22:48:08 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void	sigint_handler(int sig)
{
	t_cmd_info	*cmd_info;
	int			prompt_len;

	(void)sig;
	cmd_info = cmd_info_sta(NULL);
	if (cmd_info == NULL)
		err_exit("Error cmd_info_sta");
	cmd_move_cursor_end(cmd_info);
	write(1, "\n", 1);
	prompt_len = print_prompt();
	cmd_info_init(cmd_info, prompt_len, cmd_info->cmd_buf, cmd_info->options);
}
