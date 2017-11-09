/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:51:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 15:56:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

static void	sigint_handler(int sig)
{
	t_cmd_info	*cmd_info;
	int			prompt_len;

	(void)sig;
	cmd_info = cmd_info_sta(NULL);
	if (cmd_info == NULL)
		err_exit("Error cmd_info_sta");
	write(1, "^C\n", 3);
	prompt_len = print_prompt();
	init_cmd(cmd_info, prompt_len, cmd_info->cmd_buf, cmd_info->options);
}

void		init_signals(void)
{
	int		sig;

	sig = 1;
	while (sig <= 31)
	{
		if (sig != SIGKILL && sig != SIGSTOP)
			if (signal(sig, SIG_IGN) == SIG_ERR)
				err_exit("Error signal");
		++sig;
	}
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		err_exit("Error signal");
}
