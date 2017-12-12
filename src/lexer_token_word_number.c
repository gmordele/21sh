/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_word_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:03:52 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:42:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

t_token		*lexer_token_word(char **cmd)
{
	char	c;
	char	*start;
	char	*value;
	t_token	*new_token;

	start = *cmd;
	while (!lexer_is_op_char(**cmd) && **cmd != '\0' && !ft_isspace(**cmd))
	{
		if ((c = **cmd) == '\"' || c == '\'' || c == '`')
		{
			++(*cmd);
			while (**cmd != c && **cmd != '\0')
				++(*cmd);
		}
		if (**cmd != '\0')
			++(*cmd);
	}
	if ((value = ft_strndup(start, *cmd - start)) == NULL)
		err_exit("Error lexer_token_word");
	if ((new_token = (t_token *)malloc(sizeof(t_token))) == NULL)
		err_exit("Error lexer_token_word");
	new_token->value = value;
	new_token->type = WORD;
	return (new_token);
}

t_token		*lexer_token_number(char **cmd)
{
	char	*start;
	char	*end;
	char	*value;
	t_token *new_token;

	start = *cmd;
	end = *cmd;
	while (*end >= '0' && *end <= '9' && *end != '\0')
		++end;
	if (*end == '<' || *end == '>')
	{
		if ((value = ft_strndup(start, end - start)) == NULL)
			err_exit("Error lexer_token_number");
		if ((new_token = (t_token *)malloc(sizeof(t_token))) == NULL)
			err_exit("Error lexer_token_number");
		new_token->value = value;
		new_token->type = IO_NUMBER;
		*cmd = end;
		return (new_token);
	}
	else
		return (lexer_token_word(cmd));
}
