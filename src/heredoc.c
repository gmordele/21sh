/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:36:24 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/04 00:58:51 by gmordele         ###   ########.fr       */
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

	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		err_exit("Error signal");	
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

	init_signals();
	if ((cap = tgetstr("ei", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
}

static void	heredoc_handle_key(t_cmd_info *cmd_info, int key)
{
	if (ft_isprint(key))
		heredoc_handle_key_char(cmd_info, key);
	else if (key == KEY_LEFT || key == KEY_CTRL_B)
		heredoc_handle_key_left(cmd_info);
	else if (key == KEY_RIGHT || key == KEY_CTRL_F)
		heredoc_handle_key_right(cmd_info);
	else if (key == KEY_RETURN)
		heredoc_handle_key_return(cmd_info);
	else if (key == KEY_BACKSPACE)
		heredoc_handle_key_backspace(cmd_info);
	else if (key == KEY_DELETE)
		heredoc_handle_key_delete(cmd_info);
	else if (key == KEY_CTRL_D)
		heredoc_handle_key_ctrl_d(cmd_info);
}

static void	get_inputs(t_cmd_info *cmd_info)
{
	int			key;
	int			n;
	char		read_buf[READBUFSIZE];

	while (!cmd_info->complet)
	{
		if ((n = read(0, read_buf, READBUFSIZE)) <= 0)
			err_exit("Error read");
		key = cmd_pressed_key(n, read_buf);
		heredoc_handle_key(cmd_info, key);
	}
}

void		heredoc(t_heredoc_lst *heredoc_lst)
{
	t_cmd_info	cmd_info;	
	char		cmd_buf[CMDBUFSIZE];
	int			complet;
	char		*buf;

	enter_heredoc();
	while (heredoc_lst != NULL)
	{
		if ((buf = ft_strdup("")) == NULL)
			err_exit("Error ft_strdup");
		complet = 0;
		while (!complet)
		{
			init_cmd(&cmd_info, 2, cmd_buf, 0);
			write(1, "> ", 2);
			get_inputs(&cmd_info);
			cmd_move_down();
			complet = heredoc_check(&buf, cmd_buf, heredoc_lst);
		}
		close(heredoc_lst->fildes[1]);
		heredoc_lst = heredoc_lst->next;
	}
	exit_heredoc();
}
