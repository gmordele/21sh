/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressed_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:55:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/19 23:35:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

static int	n_1(char *read_buf)
{
	if (ft_isprint(read_buf[0]))
		return (read_buf[0]);
	if (read_buf[0] == 127)
		return (KEY_BACKSPACE);
	if (read_buf[0] == 27)
		return (KEY_ESCAPE);
	if (read_buf[0] == 10)
		return (KEY_RETURN);
	if (read_buf[0] == 4)
		return (KEY_CTRL_D);
	return (0);
}

static int	n_3(char *read_buf)
{
	if (read_buf[0] == 27 && read_buf[1] == 91)
	{
		if (read_buf[2] == 65)
			return (KEY_UP);
		if (read_buf[2] == 66)
			return (KEY_DOWN);
		if (read_buf[2] == 68)
			return (KEY_LEFT);
		if (read_buf[2] == 67)
			return (KEY_RIGHT);
	}
	return (0);
}

static int	n_4(char *read_buf)
{
	if (read_buf[0] == 27 && read_buf[1] == 91 && read_buf[2] == 51
		&& read_buf[3] == 126)
		return (KEY_DELETE);
	return (0);
}

static int	n_6(char *read_buf)
{
	if (read_buf[0] == 27 && read_buf[1] == 91 && read_buf[2] == 49
		&& read_buf[3] == 59 && read_buf[4] == 50)
	{
		if (read_buf[5] == 65)
			return (KEY_SHIFT_UP);
		if (read_buf[5] == 66)
			return (KEY_SHIFT_DOWN);
		if (read_buf[5] == 68)
			return (KEY_SHIFT_LEFT);
		if (read_buf[5] == 67)
			return (KEY_SHIFT_RIGHT);
	}
	return (0);
}

int			pressed_key(int n, char *read_buf)
{
	if (n == 1)
		return (n_1(read_buf));
	if (n == 3)
		return (n_3(read_buf));
	if (n == 4)
		return (n_4(read_buf));
	if (n == 6)
		return (n_6(read_buf));
	return (0);
}
