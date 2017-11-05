#include <term.h>
#include <stdlib.h>
#include "header.h"

static int	delete_chev(char *cap_del)
{
	if (tputs(cap_del, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_del, 1, tputc) < 0)
		err_exit("Error tputs");
	return (2);
}

static int	delete_characters(t_cmd_info *cmd_info)
{
	int		pos;
	int		col;
	char	*cap_del;
	int		shift;

	if ((cap_del = tgetstr("dc", NULL)) == NULL)
		err_exit("Error tgetstr");
	pos = cmd_info->buf_pos;
	col = cmd_info->cur_col;
	shift = 0;
	while (cmd_info->cmd_buf[pos] != '\0')
	{
		if (tputs(cap_del, 1, tputc) < 0)
			err_exit("Error tputs");
		if (((col + 1) % cmd_info->term_width == 0
			&& cmd_info->cmd_buf[pos + 1] != '\0')
			|| cmd_info->cmd_buf[pos] == '\n')
		{
			cmd_move_down();
			++shift;
		}
		col = cmd_info->cmd_buf[pos++] == '\n' ?
			delete_chev(cap_del) : col + 1;
	}
	return (shift);
}

static void	restore(int shift, int cur_col)
{
	char	*cap;

	if ((cap = tgetstr("up", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (shift-- > 0)
		if(tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if(tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (cur_col--)
		if(tputs(cap, 1, tputc) < 0)
			err_exit("Error tputs");
}

void	cmd_delete_characters(t_cmd_info *cmd_info)
{
	int		shift;
	int		cur_col;

	cur_col = cmd_info->cur_col % cmd_info->term_width;
	shift = delete_characters(cmd_info);
	restore(shift, cur_col);
}
