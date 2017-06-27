/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:39:54 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/27 19:09:58 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

int		cmd_get(char *cmd_buf, int prompt_len)
{
	(void)cmd_buf;
	(void)prompt_len;
	char	read_buf[READBUFSIZE];
	int		key;
	char *cap;
	int n;
	

	if ((n = read(0, read_buf, READBUFSIZE)) <= 0)
		err_exit("Error read");
	key = pressed_key(n, read_buf);
	if (key == KEY_ESCAPE)
		return (0);
	else if (key == KEY_BACKSPACE)
	{
		{
			if ((cap = tgetstr("le", NULL)) == NULL)
				err_exit("Error tgetstr");
			tputs(cap, 1, tputc);
			if ((cap = tgetstr("dc", NULL)) == NULL)
				err_exit("Error tgetstr");
			tputs(cap, 1, tputc);
		}
	}
	else if (ft_isprint(key) && n == 1)
		ft_printf("%c", key);
	else if (key == KEY_LEFT)
		move_cursor_left();
	else if (key == KEY_RIGHT)
		move_cursor_right();
	return (1);
}




