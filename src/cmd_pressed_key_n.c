#include "header.h"
#include "libft.h"

int	cmd_pressed_key_n_1(char *read_buf)
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
	return (0);
}

int	cmd_pressed_key_n_3(char *read_buf)
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
	return (0);
}

int	cmd_pressed_key_n_4(char *read_buf)
{
	if (read_buf[0] == 27 && read_buf[1] == 91 && read_buf[2] == 51
		&& read_buf[3] == 126)
		return (KEY_DELETE);
	return (0);
}

int	cmd_pressed_key_n_6(char *read_buf)
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
