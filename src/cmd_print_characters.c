#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"



static int	print_characters(t_cmd_info *cmd_info)
{
	int		pos;
	int		col;
	int		shift;

	col = cmd_info->cur_col;
	pos = cmd_info->buf_pos;
	shift = 0;
	while (cmd_info->cmd_buf[pos] != 0)
	{
		if (cmd_info->cmd_buf[pos++] !=  '\n'){
			write(1, cmd_info->cmd_buf + pos - 1, 1);
			if ((++col) % cmd_info->term_width == 0
				&& cmd_info->cmd_buf[pos] != '\0')
				++shift;
		}
		else
		{
			if (col % cmd_info->term_width == 0)
				cmd_move_down();
			write(1, "\n> ", 3);
			col = 2;
			++shift;
		}
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

void		cmd_print_characters(t_cmd_info *cmd_info)
{
	int		shift;
	int		cur_col;

	cur_col = cmd_info->cur_col % cmd_info->term_width;
	cmd_hide_cursor();
	shift = print_characters(cmd_info);
	restore(shift, cur_col);
	cmd_show_cursor();
}
