/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_key_ctrl_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:34:15 by gmordele          #+#    #+#             */
/*   Updated: 2017/10/30 00:48:48 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "header.h"

static void	print_buf(t_cmd_info *cmd_info, int fd)
{
	int		i;

	i = 0;
	while (cmd_info->cmd_buf[i] != '\0')
	{
		if ((cmd_info->cmd_buf)[i] != '\n')
		{
			if (i != cmd_info->buf_pos)
				ft_putchar_fd(cmd_info->cmd_buf[i], fd);
			else
				ft_dprintf(fd, "{BG_RED}%c{RES}", (cmd_info->cmd_buf)[i]);
		}
		else
		{
			if (i != cmd_info->buf_pos)
				ft_dprintf(fd, "$\n");
			else
				ft_dprintf(fd, "{BG_RED}${RES}\n");
		}
		++i;
	}
	if (cmd_info->buf_pos == i)
		ft_dprintf(fd, "{BG_RED} {RES}");
	else
		ft_dprintf(fd, "{BG_WHI} {RES}");
}

static void	print_elem(int i, char *s, t_cmd_info *cmd_info, int fd)
{
	int		len;

	if (cmd_info->nchar_buf < 10)
		len = 1;
	else if (cmd_info->nchar_buf < 100)
		len = 2;
	else
		len = 3;
	if (cmd_info->buf_pos != i)
		ft_dprintf(fd, "[%0*d] = %3d = %2s\n",
				len, i, (cmd_info->cmd_buf)[i], s);
	else
		ft_dprintf(fd, "[{BG_RED}%0*d{RES}] = %3d = %2s\n",
				len, i, (cmd_info->cmd_buf[i]), s);
}

static void	print_buf_arr(t_cmd_info *cmd_info, int fd)
{
	int		i;
	char	s[3];

	i = 0;
	while (cmd_info->cmd_buf[i] != '\0')
	{
		ft_memset(s, 0, 3);
		if (ft_isprint((cmd_info->cmd_buf)[i]))
			s[0] = cmd_info->cmd_buf[i];
		else if ((cmd_info->cmd_buf)[i] == '\n')
			ft_strcpy(s, "\\n");
		else
			s[0] = '.';
		print_elem(i, s, cmd_info, fd);
		++i;
	}
	print_elem(i, "0", cmd_info, fd);
}

static void	print_cmd_debug(t_cmd_info *cmd_info, int fd)
{
	ft_dprintf(fd, "--cmd_debug--\nbuf_pos = %d, nchar_buf = %d\n\n",
			cmd_info->buf_pos, cmd_info->nchar_buf);
	ft_dprintf(fd, "----\n");
	print_buf(cmd_info, fd);
	ft_dprintf(fd, "\n----\n\n");
	print_buf_arr(cmd_info, fd);
}

void		cmd_handle_key_ctrl_x(t_cmd_info *cmd_info)
{
	int		fd;

	if (!(cmd_info->options & OPT_DEBUG))
		return ;
	fd = open("debug", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		err_exit("Error open()");
	print_cmd_debug(cmd_info, fd);
	close(fd);
}
