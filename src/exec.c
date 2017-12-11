/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:53:16 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/11 12:33:50 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int			exec_ast_node(t_ast_node *ast_node)
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

void		exec(t_ast_lst *ast_lst)
{
	t_ast_lst	*p;

	if (ast_lst == NULL)
		return ;
	restore_term();	
	p = ast_lst;
	while (p != NULL)
	{
		exec_ast_node(p->ast_node);
		p = p->next;
	}
	init_termios();	
}
