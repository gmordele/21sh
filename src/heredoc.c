/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:36:24 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/22 00:26:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <term.h>
#include "header.h"
#include "libft.h"

static void	enter_heredoc(void)
{
	char	*cap;

	if (signal(SIGWINCH, SIG_IGN) == SIG_ERR)
		err_exit("Error signal");
	if ((cap = tgetstr("im", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

static void	exit_heredoc(void)
{
	char	*cap;

	if (signal(SIGWINCH, sigwinch_handler) == SIG_ERR)
		err_exit("Error signal");
	if ((cap = tgetstr("ei", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

static void	heredoc_handle_key(t_cmd_info *cmd_info, int key)
{
	if (ft_isprint(key))
		heredoc_handle_key_char(cmd_info, key);
}

void		heredoc(t_heredoc_lst *heredoc_lst)
{
	t_cmd_info	cmd_info;	
	char		cmd_buf[CMDBUFSIZE];
	int			key;
	int			n;
	char				read_buf[READBUFSIZE];

	cmd_info_init(&cmd_info, 2, cmd_buf, 0);
	enter_heredoc();
	while (heredoc_lst != NULL)
	{
		while (!cmd_info.complet)
		{
			if ((n = read(0, read_buf, READBUFSIZE)) <= 0)
				err_exit("Error read");
			key = cmd_pressed_key(n, read_buf);
			heredoc_handle_key(&cmd_info, key);
		}
		close(heredoc_lst->fildes[1]);
		heredoc_lst = heredoc_lst->next;
	}
	exit_heredoc();
}
