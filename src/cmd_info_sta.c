#include <stdlib.h>
#include "header.h"

t_cmd_info	*cmd_info_sta(t_cmd_info *cmd_info)
{
	static t_cmd_info	*cmd_info_sta = NULL;

	if (cmd_info != NULL)
		cmd_info_sta = cmd_info;
	return (cmd_info_sta);
}
