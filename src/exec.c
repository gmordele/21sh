/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:53:16 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/15 04:36:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "header.h"

static int			exec_cmd_node(t_ast_node *ast_node)
{
	int ret;

	ret = exec_cmd(ast_node->ast_cmd_node);
	return (ret);
}

static int			exec_andor_node(t_ast_node *ast_node)
{
	int	ret_left;

	ret_left = exec_ast_node(ast_node->ast_andor_node.left);
	if (ast_node->ast_andor_node.andor_type == AND_IF)
	{
		if (!ret_left)
			return (exec_ast_node(ast_node->ast_andor_node.right));
		else
			return (1);
	}
	else if (ast_node->ast_andor_node.andor_type == OR_IF)
	{
		if (ret_left)
			return (exec_ast_node(ast_node->ast_andor_node.right));
		else
			return (1);
	}
	err_exit("Error exec_andor_node");
	return (0);
}

int					exec_ast_node(t_ast_node *ast_node)
{
	if (ast_node == NULL)
		err_exit("Error exec_ast_node");
	if (ast_node->type == ANDOR_NODE)
	{
		return (exec_andor_node(ast_node));
	}
	else if (ast_node->type == CMD_NODE)
		return (exec_cmd_node(ast_node));
	else
		err_exit("Error exec_ast_node");
	return (0);
}

static void			init_signal_exec(void)
{
	if (signal(SIGINT, sigint_handle_exec) == SIG_ERR)
		err_exit("Error signal");
	if (signal(SIGWINCH, SIG_IGN) == SIG_ERR)
		err_exit("Error signal");
}

void				exec(t_ast_lst *ast_lst)
{
	t_ast_lst		*p;
	t_heredoc_lst	*heredoc_lst;

	if (ast_lst == NULL)
		return ;
	heredoc_lst_get(&heredoc_lst, ast_lst);
	heredoc(heredoc_lst);
	restore_term();
	init_signal_exec();
	p = ast_lst;
	while (p != NULL)
	{
		exec_ast_node(p->ast_node);
		p = p->next;
	}
	exec_close_fildes();
	heredoc_lst_free(heredoc_lst);
	init_termios();
	init_signals();
}
