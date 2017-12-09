/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 04:22:22 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 19:58:14 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

t_ast_lst	*parser(t_token_lst *token_lst)
{
	t_token_lst	*cur_token;
	int			error;
	t_ast_lst	*ast_lst;
	
	if (token_lst == NULL)
		return (NULL);
	cur_token = token_lst;
	error = 0;
	ast_lst = parser_complete_command(&cur_token, &error);
	if (error)
	{
		if (cur_token != NULL)
			ft_dprintf(2, "21sh: syntax error near unexpected token `%s'\n",
					   cur_token->token->value);
		else
			ft_dprintf(2, "21sh: syntax error: unexpected end of file\n");
		parser_free(&ast_lst);
		return (NULL);
	}
	return (ast_lst);
}
