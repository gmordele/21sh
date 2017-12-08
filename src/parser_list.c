/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:42:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 19:43:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static t_ast_lst	*new_ast_lst(t_ast_node *ast_node)
{
	t_ast_lst	*ast_lst;

	if ((ast_lst = malloc(sizeof(t_ast_lst))) == NULL)
		err_exit("Error malloc");
	ast_lst->ast_node = ast_node;
	ast_lst->next = NULL;
	return (ast_lst);
}

static void			add_ast_lst(t_ast_lst **ast_lst, t_ast_node *ast_node)
{
	t_ast_lst	*new;
	t_ast_lst	*p;

	if (ast_lst == NULL)
		err_exit("Error add_ast_lst");
	new = new_ast_lst(ast_node);
	if (*ast_lst == NULL)
		*ast_lst = new;
	else
	{
		p = *ast_lst;
		while (p->next != NULL)
			p = p->next;
		p->next = new;
	}
}

t_ast_lst			*parser_list(t_token_lst **cur_token, int *error)
{
	t_ast_lst	*ast_lst;
	t_ast_node	*ast_node;
	int			token_type;

	ast_lst = NULL;
	ast_node = parser_andor(cur_token, error);
	add_ast_lst(&ast_lst, ast_node);
	if (*error)
		return (ast_lst);
	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	while (token_type == SEMI || token_type == AND)
	{
		if ((*cur_token)->next == NULL)
			break ;
		parser_eat(cur_token, token_type);
		ast_node = parser_andor(cur_token, error);
		add_ast_lst(&ast_lst, ast_node);
		if (*error)
			return (ast_lst);
		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	}
	return (ast_lst);
}
