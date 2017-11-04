#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

static void	delete_chev(char *cap_del)
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
	if (tputs(cap_del, 1, tputc) < 0)
		err_exit("Error tputs");
}

static void	delete_characters(t_cmd_info *cmd_info)
{
	int		pos;
	char	*cap_del;

	if ((cap_del = tgetstr("dc", NULL)) == NULL)
		err_exit("Error tgetstr");
	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != '\0')
	{
		if (tputs(cap_del, 1, tputc) < 0)
			err_exit("Error tputs");
		if (cmd_info->cmd_buf[pos] == '\n')
			delete_chev(cap_del);
		++pos;
	}
}

static void	print_characters(t_cmd_info *cmd_info)
{
	int		pos;

	pos = cmd_info->buf_pos;
	while (cmd_info->cmd_buf[pos] != 0)
	{
		if (cmd_info->cmd_buf[pos] !=  '\n')
			write(1, cmd_info->cmd_buf + pos, 1);
		else
			write(1, "\n> ", 3);
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
