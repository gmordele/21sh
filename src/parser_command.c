/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:18:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 20:38:49 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		valid_cmd(int t)
{
	return (t == WORD || t == IO_NUMBER || t == DLESS || t == DGREAT
			|| t == LESSAND || t == GREATAND || t == GREAT || t == LESS);
}

void			parser_command(t_ast_node *cmd_node, t_token_lst **cur_token,
							int *error)
{
	int			token_type;

	(void)cmd_node;
	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	if (!valid_cmd(token_type))
	{
		*error = 1;
		return ;
	}
	while (valid_cmd(token_type))
	{
		parser_eat(cur_token, token_type);
		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	}
}
