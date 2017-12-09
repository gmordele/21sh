/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:38:58 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 18:54:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void	print_cmd(t_ast_node *ast_node, int n)
{
	t_word_lst *w;
	t_redir_lst	*rl;
	t_redir		*r;

	for (int i = 0; i < n; i++)
		ft_putchar(' ');
	ft_printf("cmd:\n");
	for (int i = 0; i < n; i++)
		ft_putchar(' ');
	ft_printf("words:");
	for (w = ast_node->ast_cmd_node.word_lst; w != NULL; w = w->next)
		ft_printf(" %s", w->word);
	ft_putchar('\n');
	for (int i = 0; i < n; i++)
		ft_putchar(' ');
	ft_printf("redirections:");
	for (rl = ast_node->ast_cmd_node.redir_lst; rl != NULL; rl = rl->next)
	{
		r = rl->redir;
		ft_printf(" %s", r->n);
		if (r->type == REDIR_IN)
			ft_printf("<");
		else if (r->type == REDIR_OUT)
			ft_printf(">");
		else if (r->type == REDIR_OUT_APP)
			ft_printf(">>");
		else if (r->type == REDIR_HERE)
			ft_printf("<<");
		else if (r->type == REDIR_DUP_IN)
			ft_printf("<&");
		else if (r->type == REDIR_DUP_OUT)
			ft_printf(">&");
		else
			ft_printf(" unknown redirect ");
		
		ft_printf("%s", r->word);
	}
	ft_putchar('\n');
	if (ast_node->ast_cmd_node.next_pipe != NULL)
	{
		for (int i = 0; i < n; i++)
			ft_putchar(' ');
		ft_printf("|\n");
		print_cmd(ast_node->ast_cmd_node.next_pipe, n + 1);
	}
}

void	print_node(t_ast_node *ast_node)
{
	if (ast_node->type == ANDOR_NODE)
	{
		print_node(ast_node->ast_andor_node.left);
		if (ast_node->ast_andor_node.andor_type == AND_IF)
			ft_printf("&&\n");
		else if (ast_node->ast_andor_node.andor_type == OR_IF)
			ft_printf("||\n");
		else
			ft_printf("Unknown ANDOR_NODE");
		print_node(ast_node->ast_andor_node.right);
	}
	else if (ast_node->type == CMD_NODE)
		print_cmd(ast_node, 0);
	else
		ft_printf("Unknown node");
}

void	parser_print(t_ast_lst *ast_lst)
{
	t_ast_lst *p;

	p = ast_lst;
	while (p != NULL)
	{
		ft_printf("-----------------------------------------------------\n");
		print_node(p->ast_node);
		p = p->next;
	}
}
