#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"

unsigned short	cmd_get_term_width(void)
{
	struct winsize	w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) < 0)
		err_exit("Error ioctl");
	return (w.ws_col);
}
