/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command_add_redir.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 03:40:44 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 05:39:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static int		valid_io_token(int t)
{
	return (t == IO_NUMBER || t == DLESS || t == DGREAT
			|| t == LESSAND || t == GREATAND || t == GREAT || t == LESS);
}

static void		add_redir(t_ast_node *cmd_node, t_redir *redir)
{
	t_redir_lst	*redir_lst;
	t_redir_lst	*p;

	if (redir == NULL || cmd_node == NULL)
		err_exit("Error add_redir");
	if ((redir_lst = malloc(sizeof(t_redir_lst))) == NULL)
		err_exit("Error malloc");
	redir_lst->next = NULL;
	redir_lst->redir = redir;
	if (cmd_node->ast_cmd_node.redir_lst == NULL)
	{
		cmd_node->ast_cmd_node.redir_lst = redir_lst;
		return ;
	}
	p = cmd_node->ast_cmd_node.redir_lst;
	while (p->next != NULL)
		p = p->next;
	p->next = redir_lst;
}

void			parser_command_add_redir(t_ast_node *cmd_node,
										 t_token_lst **cur_token, int *error)
{
	int		token_type;
	char	*n;
	t_redir	*redir;

	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	n = (token_type == IO_NUMBER) ? (*cur_token)->token->value : NULL;
	if (n != NULL)
		parser_eat(cur_token, IO_NUMBER);
	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	if (!valid_io_token(token_type))
	{
		*error = 1;
		return ;
	}
	redir = parser_redir(n, cur_token, error);
	if (*error)
		return ;
	add_redir(cmd_node, redir);
}
