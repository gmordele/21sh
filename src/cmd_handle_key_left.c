#include "header.h"

void	cmd_handle_key_left(t_cmd_info *cmd_info)
{
	if (cmd_info->buf_pos > 0)
	{	
		cmd_move_cursor_left(cmd_info);
		--(cmd_info->buf_pos);
	}

}
