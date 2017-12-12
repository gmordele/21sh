/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:18:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:20:42 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static int			valid_cmd(int t)
{
	return (t == WORD || t == IO_NUMBER || t == DLESS || t == DGREAT
			|| t == LESSAND || t == GREATAND || t == GREAT || t == LESS);
}

static t_word_lst	*new_word_lst(char *word)
{
	t_word_lst	*new;

	if ((new = malloc(sizeof(t_word_lst))) == NULL)
		err_exit("Error malloc");
	new->next = NULL;
	new->word = word;
	return (new);
}

static void			l_add_word(t_word_lst **word_lst, char *word)
{
	t_word_lst	*p;

	if (word_lst == NULL)
		err_exit("Error _add_word");
	if (*word_lst == NULL)
	{
		*word_lst = new_word_lst(word);
		return ;
	}
	p = *word_lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new_word_lst(word);
}

static void			add_word(t_ast_node *cmd_node, t_token_lst **cur_token)
{
	char	*exp_word;
	char	*unquoted_word;

	exp_word = exp_variable((*cur_token)->token->value);
	if (*exp_word != '\0')
	{
		unquoted_word = exp_remove_quotes(exp_word);
		l_add_word(&(cmd_node->ast_cmd_node.word_lst), unquoted_word);
	}
	free(exp_word);
	parser_eat(cur_token, WORD);
}

void				parser_command(t_ast_node *cmd_node,
								t_token_lst **cur_token, int *error)
{
	int			token_type;

	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	if (!valid_cmd(token_type))
	{
		*error = 1;
		return ;
	}
	while (valid_cmd(token_type))
	{
		if (token_type == WORD)
			add_word(cmd_node, cur_token);
		else
			parser_command_add_redir(cmd_node, cur_token, error);
		if (*error)
			return ;
		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	}
}
