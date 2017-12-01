/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:33:42 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/01 05:19:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static t_token		*lexer_token_op4(char **cmd, t_token **new_token)
{
	if (**cmd == '<')
	{
		if (*(++(*cmd)) == '&')
		{
			++(*cmd);
			(*new_token)->type = LESSAND;
			(*new_token)->value = ft_strdup("<&");
			return (*new_token);
		}
		else if (**cmd == '<')
		{
			++(*cmd);
			(*new_token)->type = DLESS;
			(*new_token)->value = ft_strdup("<<");
			return (*new_token);
		}
		(*new_token)->type = LESS;
		(*new_token)->value = ft_strdup("<");
		return (*new_token);
	}
	return (NULL);
}

static t_token		*lexer_token_op3(char **cmd, t_token **new_token)
{
	if (**cmd == '>')
	{
		if (*(++(*cmd)) == '&')
		{
			++(*cmd);
			(*new_token)->type = GREATAND;
			(*new_token)->value = ft_strdup(">&");
			return (*new_token);
		}
		else if (**cmd == '>')
		{
			++(*cmd);
			(*new_token)->type = DGREAT;;
			(*new_token)->value = ft_strdup(">>");
			return (*new_token);
		}
		(*new_token)->type = GREAT;
		(*new_token)->value = ft_strdup(">");
		return (*new_token);
	}
	return (lexer_token_op4(cmd, new_token));
}

static t_token		*lexer_token_op2(char **cmd, t_token **new_token)
{
	if (**cmd == '|')
	{
		if (*(++(*cmd)) == '|')
		{
			++(*cmd);
			(*new_token)->type = OR_IF;
			(*new_token)->value = ft_strdup("||");
			return (*new_token);
		}
		(*new_token)->type = OR;
		(*new_token)->value = ft_strdup("|");
		return (*new_token);
	}
	return (lexer_token_op3(cmd, new_token));
}

t_token				*lexer_token_op(char **cmd)
{
	t_token *new_token;

	if ((new_token = (t_token *)malloc(sizeof(t_token))) == NULL)
		err_exit("Error lexer_token_op");
	if (**cmd == ';')
	{
		++(*cmd);
		new_token->type = SEMI;
		new_token->value = ft_strdup(";");
		return (new_token);
	}
	if (**cmd == '&')
	{
		if (*(++(*cmd)) == '&')
		{
			++(*cmd);
			new_token->type = AND_IF;
			new_token->value = ft_strdup("&&");
			return (new_token);
		}
		new_token->type = AND;
		new_token->value = ft_strdup("&");
		return (new_token);
	}
	return (lexer_token_op2(cmd, &new_token));
}


