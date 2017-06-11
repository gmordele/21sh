/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:05:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 19:40:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "libft.h"
#include "header.h"

static void	main_loop(void)
{
	char	cmd_buf[CMDBUFSIZE];
	int		prompt_len;

	prompt_len = ft_printf("21sh>");
	while (42)
	{
		get_cmd(cmd_buf, prompt_len);
	}
}

int			main(int argc, char *argv[])
{
	t_term_info	term;
	int			options;
	t_env_lst	*head_env;

	(void)head_env;
	options = get_options(argc, argv);
	init_termcap();
	head_env = get_env_lst();
	sta_env_lst(&head_env);
	init_termios(&term);
	init_signals();
	if (options & OPT_KEYS)
		print_keys();
	else
		main_loop();
	normal_exit();
}
