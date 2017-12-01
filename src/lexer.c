/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 04:01:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/01 03:34:19 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	skip_whitespace(char **cmd)
{
	while (ft_isspace(**cmd) && **cmd != '\0')
		++(*cmd);
}

static t_token	*get_next_token(char **cmd)
{
	skip_whitespace(cmd);
	if (**cmd == '\0')
		return (NULL);
	if (lexer_is_op_char(**cmd))
		return (lexer_token_op(cmd));
	else if (**cmd >= '0' && **cmd <= '9')
		return (lexer_token_number(cmd));
	else
		return (lexer_token_word(cmd));
}

t_token_lst	*lexer(char *cmd_buf)
{
	char		*cmd;
	t_token_lst	*token_lst;
	t_token		*token;

	cmd = cmd_buf;
	token_lst = NULL;
	while ((token = get_next_token(&cmd)) != NULL)
		token_lst_add(&token_lst, token);
	return (token_lst);
}
