/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_return.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:51:01 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:43:55 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "header.h"

static void	find_match(char **buf, char c, int *open)
{
	++(*buf);
	*open = 1;
	while (**buf != '\0')
	{
		if (**buf == c)
		{
			*open = 0;
			++(*buf);
			return ;
		}
		++(*buf);
	}
}

static int	is_complet(t_cmd_info *cmd_info)
{
	int		open;
	char	c;
	char	*buf;

	buf = cmd_info->cmd_buf;
	open = 0;
	while (*buf != '\0')
	{
		if (*buf == '\'' || *buf == '"')
		{
			c = *buf;
			find_match(&buf, c, &open);
		}
		else
			++buf;
	}
	return (!open);
}

static void	return_hist_handle(t_cmd_info *cmd_info)
{
	if (cmd_info->cmd_buf[0] != '\0')
		hist_lst_add(cmd_info->cmd_buf);
	if (!cmd_info->in_main_buf && cmd_info->hist_lst != NULL)
		ft_memcpy(cmd_info->hist_lst->cmd, cmd_info->hist_lst->cmd_unchanged,
			CMDBUFSIZE);
}

void		cmd_handle_key_return(t_cmd_info *cmd_info)
{
	if (cmd_info->in_clipboard)
		cmd_exit_clipboard(cmd_info);
	cmd_move_cursor_end(cmd_info);
	if (is_complet(cmd_info))
	{
		cmd_info->complet = 1;
		return_hist_handle(cmd_info);
		write(1, "\n", 1);
	}
	else
	{
		if (cmd_info->nchar_buf >= CMDBUFSIZE - 1)
			return ;
		write(1, "\n> ", 3);
		++(cmd_info->cur_line);
		cmd_info->cur_col = 2;
		while (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
			++(cmd_info->buf_pos);
		cmd_insert_char(cmd_info, '\n');
		++(cmd_info->buf_pos);
	}
}
