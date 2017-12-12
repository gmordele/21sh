/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_andor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:27:16 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:20:05 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static t_ast_node	*new_andor_node(int type, t_ast_node *left)
{
	t_ast_node *andor_node;

	if ((andor_node = malloc(sizeof(t_ast_node))) == NULL)
		err_exit("Error malloc");
	andor_node->type = ANDOR_NODE;
	andor_node->ast_andor_node.left = left;
	andor_node->ast_andor_node.right = NULL;
	andor_node->ast_andor_node.andor_type = type;
	return (andor_node);
}

t_ast_node			*parser_andor(t_token_lst **cur_token, int *error)
{
	t_ast_node	*ast_node;
	int			token_type;

	ast_node = parser_pipe_sequence(cur_token, error);
	if (*error)
		return (ast_node);
	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	while (token_type == AND_IF || token_type == OR_IF)
	{
		if (!parser_eat(cur_token, token_type))
		{
			*error = 1;
			return (ast_node);
		}
		ast_node = new_andor_node(token_type, ast_node);
		ast_node->ast_andor_node.right = parser_pipe_sequence(cur_token, error);
		if (*error)
			return (ast_node);
		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	}
	return (ast_node);
}
