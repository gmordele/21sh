/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:05:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/28 15:58:17 by gmordele         ###   ########.fr       */
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
//	while (42)
//	{
		//	if (!get_cmd(cmd_buf, prompt_len))
//			break;
	cmd_get(cmd_buf, prompt_len);
	ft_printf("\n|%s|\n", cmd_buf);
//	}
}

int			main(int argc, char *argv[])
{
	int				options;

	options = get_options(argc, argv);
	env_lst_get();
	init_termcap();
	init_termios();;
	init_signals();
	if (options & OPT_KEYS)
		print_keys();
	else
		main_loop();
	normal_exit();
}
