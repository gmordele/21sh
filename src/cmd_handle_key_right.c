#include "header.h"

void	cmd_handle_key_right(t_cmd_info *cmd_info)
{
	if (cmd_info->cmd_buf[cmd_info->buf_pos] != '\0')
	{
		cmd_move_cursor_right(cmd_info);
		++(cmd_info->buf_pos);
	}
}
