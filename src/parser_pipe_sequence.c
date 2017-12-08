/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:57:50 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 20:31:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static t_ast_node	*new_cmd_node(void)
{
	t_ast_cmd_node	cmd;
	t_ast_node		*new;

	if ((new = malloc(sizeof(t_ast_node))) == NULL)
		err_exit("Error malloc");
	cmd.type = CMD_NODE;
	cmd.word_lst = NULL;
	cmd.redir_lst = NULL;
	cmd.next_pipe = NULL;
	new->ast_cmd_node = cmd;
	return (new);
}

t_ast_node			*parser_pipe_sequence(t_token_lst **cur_token, int *error)
{
	t_ast_node	*cmd_node;
	int			token_type;

	cmd_node = new_cmd_node();
	parser_command(cmd_node, cur_token, error);
	if (*error)
		return (cmd_node);
	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	if (token_type == OR)
	{
		parser_eat(cur_token, OR);
		cmd_node->ast_cmd_node.next_pipe =
			parser_pipe_sequence(cur_token, error);
	}
	return (cmd_node);
}
