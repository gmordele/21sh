/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pressed_key_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:09:16 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/10 02:55:31 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

static int cmd_pressed_key_n_1_(char *read_buf)
{
	if (read_buf[0] == 7)
		return (KEY_CTRL_G);
	if (read_buf[0] == 25)
		return (KEY_CTRL_Y);
	if (read_buf[0] == 23)
		return (KEY_CTRL_W);
	if (read_buf[0] == 16)
		return (KEY_CTRL_P);
	if (read_buf[0] == 14)
		return (KEY_CTRL_N);
	if (read_buf[0] == 12)
		return (KEY_CTRL_L);
	if (read_buf[0] == 11)
		return (KEY_CTRL_K);
	if (read_buf[0] == 21)
		return (KEY_CTRL_U);
	return (0);
}

int			cmd_pressed_key_n_1(char *read_buf)
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
	if (read_buf[0] == 6)
		return (KEY_CTRL_F);
	if (read_buf[0] == 2)
		return (KEY_CTRL_B);
	if (read_buf[0] == 1)
		return (KEY_CTRL_A);
	if (read_buf[0] == 5)
		return (KEY_CTRL_E);
	if (read_buf[0] == 0)
		return (KEY_CTRL_SPACE);
	if (read_buf[0] == 27)
		return (KEY_ESCAPE);
	if (read_buf[0] == 24)
		return (KEY_CTRL_X);
	return cmd_pressed_key_n_1_(read_buf);
}

int			cmd_pressed_key_n_3(char *read_buf)
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
		if (read_buf[2] == 72)
			return (KEY_HOME);
		if (read_buf[2] == 70)
			return (KEY_END);
	}
	if (read_buf[0] == -30 && read_buf[1] == -120 && read_buf[2] == -111)
		return (KEY_ALT_W);
	return (0);
}

int			cmd_pressed_key_n_4(char *read_buf)
{
	if (read_buf[0] == 27 && read_buf[1] == 91 && read_buf[2] == 51
		&& read_buf[3] == 126)
		return (KEY_DELETE);
	return (0);
}

int			cmd_pressed_key_n_6(char *read_buf)
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
