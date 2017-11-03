#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

static void	delete_chev(char *cap_move, char *cap_del)
{
	char	*cap;

	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if ((cap = tgetstr("cr", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_del, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_move, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_del, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_move, 1, tputc) < 0)
		err_exit("Error tputs");	
}

static void	delete_characters(t_cmd_info *cmd_info)
{
	int		pos;
	char	*cap_move;
	char	*cap_del;

	if ((cap_move = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	if ((cap_del = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\0')
	{
		if (tputs(cap_del, 1, tputc) < 0)
			err_exit("Error tputs");
		if (cmd_info->cmd_buf[pos] == '\n')
			delete_chev(cap_move, cap_del);
		if (tputs(cap_move, 1, tputc) < 0)
			err_exit("Error tputs");
		++pos;
	}
}

static void	print_characters(t_cmd_info *cmd_info)
{
	int		pos;
	char	*cap;
	int		col;

	pos = cmd_info->buf_pos;
	col = cmd_info->cur_col;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		err_exit("Error tgetstr");
	while (cmd_info->cmd_buf[pos] != 0)
	{
//		if ((col + 1) % cmd_info->term_width == 0)
//			cmd_move_down();
		write(1, cmd_info->cmd_buf + pos, 1);		
		++col;
		++pos;
	}
}

void		cmd_print_characters(t_cmd_info *cmd_info)
{
	char	*cap_save;
	char	*cap_restore;

	if ((cap_save = tgetstr("sc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap_save, 1, tputc) < 0)
		err_exit("Error tputs");
	delete_characters(cmd_info);
	if ((cap_restore = tgetstr("rc", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap_restore, 1, tputc) < 0)
		err_exit("Error tputs");
	if (tputs(cap_save, 1, tputc) < 0)
		err_exit("Error tputs");
	print_characters(cmd_info);
	if (tputs(cap_restore, 1, tputc) < 0)
		err_exit("Error tputs");
	
}
