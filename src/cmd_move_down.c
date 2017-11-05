#include <term.h>
#include <stdlib.h>
#include "header.h"

void	cmd_move_down(void)
{
	char *cap;

/* 	if ((cap = tgetstr("do", NULL)) == NULL) */
/* 		err_exit("Error tgetstr"); */
/* 	if (tputs(cap, 1, tputc) < 0) */
/* 		err_exit("Error tputs"); */
/* 	if ((cap = tgetstr("cr", NULL)) == NULL) */
/* 		err_exit("Error tgetstr"); */
/* 	if (tputs(cap, 1, tputc) < 0) */
/* 		err_exit("Error tputs"); */
	if ((cap = tgetstr("do", NULL)) == NULL)
		err_exit("Error tgetstr");
	if (tputs(cap, 1, tputc) < 0)
		err_exit("Error tputs");
	
}
