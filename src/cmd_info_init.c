/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:10:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 20:11:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		cmd_info_init(t_cmd_info *cmd_info, int prompt_len, char *cmd_buf,
					int options)
{
	static int start = 1;

	cmd_info->options = options;
	ft_memset(cmd_buf, 0, CMDBUFSIZE);
	cmd_info->cmd_buf = cmd_buf;
	cmd_info->prompt_len = prompt_len;
	cmd_info->cur_line = 0;
	cmd_info->cur_col = prompt_len;
	cmd_info->complet = 0;
	cmd_info->buf_pos = 0;
	cmd_info->nchar_buf = 0;
	cmd_info->term_width = cmd_get_term_width();
	cmd_info->in_clipboard = 0;
	if (start == 1)
	{
		start = 0;
		ft_memset(cmd_info->clip_buf, 0, CMDBUFSIZE);
	}
	cmd_info->hist_lst = *hist_lst_sta(NULL);
	cmd_info->in_main_buf = 1;
	ft_memset(cmd_info->main_buf, 0, CMDBUFSIZE);
}
