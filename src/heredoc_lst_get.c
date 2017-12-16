/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_lst_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:09:15 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/16 04:16:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static void	get_heredoc(t_heredoc_lst **heredoc_lst, t_redir_lst *redir_lst)
{
	int		fildes[2];

	while (redir_lst != NULL)
	{
		if (redir_lst->redir->type == REDIR_HERE)
		{
			heredoc_lst_add(heredoc_lst, redir_lst->redir->word, fildes);
			redir_lst->redir->here_fildes[0] = fildes[0];
			redir_lst->redir->here_fildes[1] = fildes[1];
		}
		redir_lst = redir_lst->next;
	}
}

static void	heredoc_get_node(t_heredoc_lst **heredoc_lst, t_ast_node *ast_node)
{
	if (ast_node == NULL)
		err_exit("Error exec_ast_node");
	if (ast_node->type == ANDOR_NODE)
	{
		heredoc_get_node(heredoc_lst, ast_node->ast_andor_node.left);
		heredoc_get_node(heredoc_lst, ast_node->ast_andor_node.right);
	}
	else if (ast_node->type == CMD_NODE)
		get_heredoc(heredoc_lst, ast_node->ast_cmd_node.redir_lst);
	else
		err_exit("Error exec_ast_node");
}

void		heredoc_lst_get(t_heredoc_lst **heredoc_lst, t_ast_lst *ast_lst)
{
	*heredoc_lst = NULL;
	while (ast_lst != NULL)
	{
		heredoc_get_node(heredoc_lst, ast_lst->ast_node);
		ast_lst = ast_lst->next;
	}
}
