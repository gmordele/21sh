/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:05:04 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 04:06:54 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "libft.h"
#include "header.h"

int			print_prompt(void)
{
	return (ft_printf("21sh:%s$ ", env_lst_get_value("PWD")));
}

static void	main_loop(int options)
{
	char		cmd_buf[CMDBUFSIZE];
	int			prompt_len;
	t_token_lst *token_lst;
	t_ast_lst	*ast_lst;

	while (42)
	{
		prompt_len = print_prompt();
		cmd_get(cmd_buf, prompt_len, options);
		token_lst = lexer(cmd_buf);
		ast_lst = parser(token_lst);
		ast_lst_sta(&ast_lst, 0);
		token_lst_free(&token_lst);
		exec(ast_lst);
		parser_free(&ast_lst);
		ast_lst_sta(NULL, 1);
	}
}

int			main(int argc, char *argv[])
{
	int				options;

	options = get_options(argc, argv);
	env_lst_get();
	init_termcap();
	init_termios();
	hist_lst_init();
	init_signals();
	if (options & OPT_KEYS)
		print_keys();
	else if (options & OPT_HELP)
		print_help();
	else
		main_loop(options);
	normal_exit();
}
