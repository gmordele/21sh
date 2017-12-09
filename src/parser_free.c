/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:34:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 19:54:46 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static void free_redir_lst(t_redir_lst *redir_lst)
{
	if (redir_lst == NULL)
		return ;
	if (redir_lst->next != NULL)
		free_redir_lst(redir_lst->next);
	if (redir_lst->redir == NULL)
		err_exit("Error free_redir_lst");
	if (redir_lst->redir->n == NULL || redir_lst->redir->word == NULL)
		err_exit("Error free_redir_lst");
	free(redir_lst->redir->n);
	free(redir_lst->redir->word);
	free(redir_lst->redir);
	free(redir_lst);
}

static void free_word_lst(t_word_lst *word_lst)
{
	if (word_lst == NULL)
		return ;
	if (word_lst->next != NULL)
		free_word_lst(word_lst->next);
	free(word_lst->word);
	free(word_lst);
}

static void	free_cmd_node(t_ast_node *ast_node)
{
	free_word_lst(ast_node->ast_cmd_node.word_lst);
	free_redir_lst(ast_node->ast_cmd_node.redir_lst);
	if (ast_node->ast_cmd_node.next_pipe != NULL)
		free_cmd_node(ast_node->ast_cmd_node.next_pipe);
	free(ast_node);
}

static void	free_ast_node(t_ast_node *ast_node)
{
	if (ast_node == NULL)
		err_exit("Error free_ast_node");
	if (ast_node->type == ANDOR_NODE)
	{
		free_ast_node(ast_node->ast_andor_node.left);
		free_ast_node(ast_node->ast_andor_node.right);
		free(ast_node);
	}
	else if (ast_node->type == CMD_NODE)
		free_cmd_node(ast_node);
	else
		err_exit("Error free_ast_node");
}

void		parser_free(t_ast_lst **ast_lst)
{
	t_ast_lst	*p;
	t_ast_lst	*p2;

	if (ast_lst == NULL)
		err_exit("Error parser_free");
	p = *ast_lst;
	while (p != NULL)
	{
		p2 = p->next;
		free_ast_node(p->ast_node);
		free(p);
		p = p2;
	}
	*ast_lst = NULL;
}
