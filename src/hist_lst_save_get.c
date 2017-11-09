/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_lst_save_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 03:03:53 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 04:34:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

void			hist_lst_save(void)
{
	int			fd;
	t_hist_lst	*hist_lst;
	char		c;
	int			i;

	if ((hist_lst = *hist_lst_sta(NULL)) == NULL)
		return ;
	if ((fd = open("history", O_CREAT | O_WRONLY, 0666)) < 0)
		err_exit("Error open");
	c = 0;
	i = 0;
	while (hist_lst->prev != NULL && i < HISTMAX)
	{
		hist_lst = hist_lst->prev;
		++i;
	}
	while (hist_lst != NULL)
	{
		ft_dprintf(fd, hist_lst->cmd);
		write(fd, &c, 1);
		hist_lst = hist_lst->next;
	}
	close(fd);
}

static void get(char *cmd_buf, char *read_buf, int fd)
{
	int		i;
	int		j;
	ssize_t	n;

	i = 0;
	while ((n = read(fd, read_buf, HISTRDBUFSIZE)) != 0)
	{
		if (n < 0)
			err_exit("Error read");
		j = 0;
		while (j < n)
		{
			if (i >= CMDBUFSIZE)
				err_exit("Error hist_lst_get");
			cmd_buf[i] = read_buf[j];
			if (cmd_buf[i++] == '\0')
			{
				hist_lst_add(cmd_buf);
				i = 0;
			}
			++j;
		}
	}
}

void		hist_lst_get(void)
{
	char	cmd_buf[CMDBUFSIZE];
	char	read_buf[HISTRDBUFSIZE];
	int		fd;
	
	if ((fd = open("history", O_RDONLY)) < 0)
		return ;
	get(cmd_buf, read_buf, fd);
}
