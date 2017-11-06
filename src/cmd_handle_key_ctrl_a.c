#include "header.h"

void	cmd_handle_key_ctrl_a(t_cmd_info *cmd_info)
{
	while (cmd_info->buf_pos != 0)
	{
		if (cmd_info->cmd_buf[cmd_info->buf_pos - 1] == '\n')
			break ;
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}
}
